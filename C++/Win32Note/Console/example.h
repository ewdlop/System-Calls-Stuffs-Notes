#ifndef EXAMPLE_H
#define EXAMPLE_H


#ifdef __cplusplus
extern "C" {
#endif

    void c_function();

#ifdef __cplusplus
}
namespace MyLibrary {
    void cpp_function();
}
#endif

#endif // EXAMPLE_H
