project(
    'eprosima-test',
    'cpp',
    version: '0.1',
    default_options: ['warning_level=3', 'cpp_std=c++14'],
)

test_idl = custom_target(
    'Test.idl',
    command: [
        find_program('fastddsgen'),
        '-d', '@OUTDIR@',
        '-typeobject',
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

exe = executable('eprosima_test', 'eprosima_test.cpp', test_idl, install: true)

test('basic', exe)
