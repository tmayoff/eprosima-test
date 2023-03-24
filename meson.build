project(
    'eprosima-test',
    'cpp',
    version: '0.1',
    default_options: ['warning_level=3', 'cpp_std=c++17'],
)

# add_project_arguments('-DFASTRTPS_DYN_LINK=1', language: 'cpp')

idls = ['HelloWorld.idl']

sources = files('eprosima_test.cpp', 'subscriber.cpp')
foreach idl : idls
    sources += custom_target(
        idl,
        command: [
            find_program('fastddsgen'),
            '-typeobject',
            '-replace', '@INPUT@',
            '-d', '@OUTDIR@',
        ],
        input: idl,
        output: [
            '@BASENAME@.h',
            '@BASENAME@.cxx',
            '@BASENAME@PubSubTypes.h',
            '@BASENAME@PubSubTypes.cxx',
            '@BASENAME@TypeObject.h',
            '@BASENAME@TypeObject.cxx',
        ],
    )
endforeach

sources += custom_target(
    'TestInclude.idl',
    command: [
        find_program('fastddsgen'),
        '-d', '@OUTDIR@',
        '-I', meson.current_source_dir(),
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
    sources,
    dependencies: [fastdds],
    install: true,
)

test('basic', exe)
