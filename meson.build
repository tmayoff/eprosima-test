project(
    'eprosima-test',
    'cpp',
    version: '0.1',
    default_options: ['warning_level=3', 'cpp_std=c++20'],
)

add_project_arguments('-DFASTRTPS_DYN_LINK=1', language: 'cpp')

test_idl = custom_target(
    'Test.idl',
    command: [
        find_program('fastddsgen'),
        '-d', '@OUTDIR@',
        '-typeobject',
        '-I', meson.current_source_dir(),
        '-replace', '@INPUT@',
    ],
    input: 'Test.idl',
    output: [
        '@BASENAME@.h',
        '@BASENAME@.cxx',
        '@BASENAME@PubSubTypes.h',
        '@BASENAME@PubSubTypes.cxx',
        '@BASENAME@TypeObject.h',
        '@BASENAME@TypeObject.cxx',
    ],
)

test_include_idl = custom_target(
    'TestInclude.idl',
    command: [
        find_program('fastddsgen'),
        '-d', '@OUTDIR@',
        '-typeobject',
        '-replace', '@INPUT@',
    ],
    input: 'TestInclude.idl',
    output: [
        '@BASENAME@.h',
        '@BASENAME@.cxx',
        '@BASENAME@TypeObject.h',
        '@BASENAME@TypeObject.cxx',
    ],
)

fastdds = dependency('fastrtps', required: false)

exe = executable(
    'eprosima_test',
    'eprosima_test.cpp',
    test_idl,
    test_include_idl,
    dependencies: [fastdds],
    install: true,
)

test('basic', exe)
