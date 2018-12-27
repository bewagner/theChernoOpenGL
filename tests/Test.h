//
// Created by benjamin on 27.12.18.
//

#ifndef OPENGL_TEST_H
#define OPENGL_TEST_H

namespace test {
    class Test {
    public:
        Test() = default;

        virtual ~Test() = default;

        virtual void OnUpdate(float deltaTime) = 0;

        virtual void OnRender() = 0;

        virtual void OnImGuiRender() = 0;

    };
}

#endif //OPENGL_TEST_H
