//
// Created by benjamin on 27.12.18.
//

#ifndef OPENGL_TESTCLEARCOLOR_H
#define OPENGL_TESTCLEARCOLOR_H

#include "Test.h"


namespace test {
    class TestClearColor : public Test {
    public:
        TestClearColor();

       ~TestClearColor() override;

        void OnUpdate(float deltaTime) override;

        void OnRender() override;

        void OnImGuiRender() override;

    private:
        float m_ClearColor[4];
    };
}


#endif //OPENGL_TESTCLEARCOLOR_H
