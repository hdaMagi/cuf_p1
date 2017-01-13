#include "LSystem.h"
#include "windowVercorized.hpp"
#include <math.h>

#define PI 3.14159265359


#include "utils.h"
#include "window3D.h"

class MyWindow : public cf::Window3D {
public:
    MyWindow(int* argc, char** argv):cf::Window3D(argc, argv, 800, 600, "Example"){
        this->m_AngleAdjustment = 2.0f; // speed up  rotation
        this->m_CameraAdjustment= 0.1f; // slow down camera movement
    }
    virtual ~MyWindow() = default;
    virtual void draw() override{
        this->clear();
        this->drawAxis(2.f);

        glm::vec4 nextDir(0.f, 0.f, 1.f, 1.f);
        float radianValue = cf::degree2radian(this->ls.getStartAngle()); // glm library uses radian format
        glm::mat4x4 rotMat = glm::rotate(radianValue, glm::vec3(1, 0, 0)); // rotation around x-axis
        nextDir = rotMat * nextDir;
        nextDir *= this->ls.getScale() / (float) (this->generation+1);

        glm::vec4 startPos;
        glm::mat4x4 transformation;
        std::vector<glm::mat4x4> transStack;
        std::vector<glm::vec4> posStack;

        std::vector<glm::vec4> stack;
        stack.push_back(nextDir);
        for(std::string::size_type i = 0; i < this->axiom.size(); i++) {
            if ((this->axiom[i] >= char('A')) && (this->axiom[i] <= char('Z'))) {
                glm::vec4 dir = stack.at(stack.size()-1);

                glm::vec4 tmp(1,0,0, 1);
                tmp = transformation * tmp;


                //this->drawCylinder(nextDir , this->m_StartPos + dir, this->m_Diameter , cf::Color::RED);
                this->drawCylinder(tmp, startPos, this->m_Diameter , cf::Color::RED);
                //dir = dir + nextDir;
                dir = dir + tmp;
                stack.at(stack.size()-1) = dir;
                startPos += tmp;


            } else if ((this->axiom[i] >= char('a')) && (this->axiom[i] <= char('z'))) {
                glm::vec4 dir = stack.at(stack.size()-1);
                dir += nextDir;
                stack.at(stack.size()-1) = dir;



                glm::vec4 tmp(1,0,0, 1);
                tmp = transformation * tmp;
                startPos += tmp;



            } else if(this->axiom[i] == '+') { //links
                // left rotation around z-axis
                nextDir = glm::rotate(this->m_AngleAdjustment,     glm::vec3(0, 0, 1)) * nextDir;
                transformation *= glm::rotate(this->m_AngleAdjustment,     glm::vec3(0, 0, 1));

            } else if(this->axiom[i] == '-') { //rechts
                // rigth rotation around z-axis
                nextDir = glm::rotate(this->m_neg_AngleAdjustment, glm::vec3(0, 0, 1)) * nextDir;
                transformation *= glm::rotate(this->m_neg_AngleAdjustment, glm::vec3(0, 0, 1));
            } else if(this->axiom[i] == '&') { //abwärts
                // left rotation around y-axis
                nextDir = glm::rotate(this->m_AngleAdjustment,      glm::vec3(0, 1, 0)) * nextDir;
                transformation *= glm::rotate(this->m_AngleAdjustment,      glm::vec3(0, 1, 0));
            } else if(this->axiom[i] == '^') { //aufwärts
                // rigth rotation around y-axis
                nextDir = glm::rotate(this->m_neg_AngleAdjustment,  glm::vec3(0, 1, 0)) * nextDir;
                transformation *= glm::rotate(this->m_neg_AngleAdjustment,  glm::vec3(0, 1, 0));
            } else if(this->axiom[i] == '*') { //rollen
                // left rotation around x-axis
                nextDir = glm::rotate(this->m_AngleAdjustment,      glm::vec3(1, 0, 0)) * nextDir;
                transformation *= glm::rotate(this->m_AngleAdjustment,      glm::vec3(1, 0, 0));
            } else if(this->axiom[i] == '/') { //rollen
                // rigth rotation around x-axis
                nextDir = glm::rotate(this->m_neg_AngleAdjustment,  glm::vec3(1, 0, 0)) * nextDir;
                transformation *= glm::rotate(this->m_neg_AngleAdjustment,  glm::vec3(1, 0, 0));
            } else if(this->axiom[i] == '[') {
                glm::vec4 dir = stack.at(stack.size()-1);
                dir += nextDir;
                stack.push_back(dir);

                transStack.push_back(transformation);
                posStack.push_back(startPos);


            } else if(this->axiom[i] == ']') {
                stack.pop_back();


                transformation = transStack.back();
                transStack.pop_back();
                startPos = posStack.back();
                posStack.pop_back();

            }

        }
    }
    std::string getAxiom(void) {
        return this->axiom;
    }
    void setAxiom(std::string axiom) {
        this->axiom = axiom;
    }
    void setLSystemParams(std::string filePath) {
        this->ls.read(filePath);
        std::string align = " :  ";
        std::cout << "Name"                    << align << this->ls.getName()                              << '\n'
                  << "Axiom"                   << align << this->ls.getAxiom()                             << '\n'
                  << "Number of productions"   << align << this->ls.getNumProductions()                    << '\n'
                  << "Clear window each time?" << align << (this->ls.clearWindowEachTime() ? "yes" : "no") << '\n'
                  << "Start angle"             << align << this->ls.getStartAngle()                        << '\n'
                  << "Adjustment angle"        << align << this->ls.getAdjustmentAngle()                   << '\n'
                  << "Scale"                   << align << this->ls.getScale()                             << '\n'
                  << "Interval X"              << align << this->ls.getRangeX()                            << '\n'
                  << "Interval Y"              << align << this->ls.getRangeY()                            << '\n'
                  << std::endl;

        // print all productions
        std::cout << std::endl << std::endl << "All productions:" << std::endl << std::endl;
        for (const auto& e: this->ls.getAllProductions()){
            std::cout << "Symbol: " << e.first << "\nProduction: " << e.second << std::endl << std::endl;
        }
        std::cout << std::endl << "--------------------------------------------" << std::endl;
        this->axiom.push_back(this->ls.getAxiom());
        this->m_AngleAdjustment = cf::degree2radian(this->ls.getAdjustmentAngle());
        this->m_neg_AngleAdjustment = cf::degree2radian(360-this->ls.getAdjustmentAngle());
    }
    void handleKeyboardInput(unsigned char key, int x, int y) override{
        int w = x;
        w = y;
        w=w;
        //printf("Key: %c pressed at mouse position: %d, %d\r", key, x, y);
        fflush(stdout);

        switch(key){
        // change cylinder positions
        case 'j': this->m_StartPos.x -= 0.1f; break;
        case 'l': this->m_StartPos.x += 0.1f; break;
        case 'k': this->m_StartPos.y -= 0.1f; break;
        case 'i': this->m_StartPos.y += 0.1f; break;

        // change cylinder thickness
        case 'n': this->m_Diameter *= 1.5f; break;
        case 'm': this->m_Diameter /= 1.5f; break;

        // change cylinder rotation
        case 'u': this->m_Angle -= 5.f; break;
        case 'o': this->m_Angle += 5.f; break;

        // next generation
        case 'g': {
            this->generation++;
            this->generateNewAxiom();
            break;
        }
        default : break;
        }

        // change cylinder length
        if (key > '0' && key <= '9')
            this->m_Length = key - '0';
    }

    /*bool handleMousePressedMovement(MouseButton btn, int x, int y) override {
        std::string button = "N/A";
        switch (btn) {
        case MouseButton::CENTER: button = "middle"; break;
        case MouseButton::LEFT:   button = "left";   break;
        case MouseButton::RIGHT:  button = "right";  break;
        default: break;
        }
        std::cout << "Mouse moved to (" << x << "," << y << ") while the "
                  << button << " button was pressed." << std::endl;
        return false; // Set returnvalue to true to prevent camera movement
    }*/

    /*void handleMousePressEvent(MouseButton btn, MouseButtonEvent ev, int x, int y) override {
        std::string button = "N/A";
        std::string event = "N/A";
        switch (btn) {
        case MouseButton::CENTER:     button = "middle";     break;
        case MouseButton::LEFT:       button = "left";       break;
        case MouseButton::RIGHT:      button = "right";      break;
        case MouseButton::WHEEL_UP:   button = "wheel up";   break;
        case MouseButton::WHEEL_DOWN: button = "wheel down"; break;
        default: break;
        }
        switch (ev) {
        case MouseButtonEvent::PRESSED:  event = "pressed";  break;
        case MouseButtonEvent::RELEASED: event = "released"; break;
        default: break;
        }
        std::cout << "Mouse at (" << x << "," << y << ") while the " << button
                  << " button was " << event << "." << std::endl;
    }*/

private:
    float m_Diameter = 0.05f;
    float m_Length = 1.f;
    float m_Angle = 0.f;
    float m_neg_AngleAdjustment = 0.f;
    glm::vec4 m_StartPos = glm::vec4(0.f, 0.f, 0.f, 0.f);
    std::string axiom;
    int axiomIdx = 0;
    int generation = 0;
    cf::LindenmayerSystem ls;
    void generateNewAxiom() {
        std::string newStr = "";
        for (std::string::size_type i = 0; i < this->axiom.size(); i++) {
            const std::string* pStr = this->ls.getProduction(this->axiom[i]);
            if (pStr != nullptr) {
                newStr += *pStr;
            } else {
                newStr += this->axiom[i];
            }
        }
        this->axiom = newStr;
    }

    void printVec4(glm::vec4 vec) {
        std::cout << vec.x << "|" << vec.y<< "|" << vec.z << std::endl;
    }
};


int main(int argc, char** argv){
// print camera usage
    MyWindow::printWindowUsage();

// print object movement options
        std::cout << std::endl << std::endl
                      << "Object movement:\n"
                          << "press:\ti/j/k/l\t to translate the object\n"
                          << "press:\tu/o    \t to   rotate  the object\n"
                      << "press: a number\t to    set    the objests length\n"
                          << "press:\tm/n    \t to   change  the objects diameter\n"
                      << std::endl;

// create window and set up camera
    MyWindow window(&argc, argv);

    std::cout << "Welche Datei soll geladen werden?" << std::endl;
    std::cout << "1) BAUM_3D_1.LIN" << std::endl;
    std::cout << "2) BAUM_3D_2.LIN" << std::endl;
    std::cout << "3) BUSCH_3D_1.LIN" << std::endl;
    std::cout << "4) BUSCH_3D_2.LIN" << std::endl;
    std::cout << "5) SIERPINSKI_PYRAMIDE_3D.LIN" << std::endl;
    std::cout << "6) HILBERT_KURVE_3D.LIN" << std::endl;
    std::cout << "Eingabe: ";
    int fileNumber;
    std::cin >> fileNumber;
    cf::Console::clearConsole();
    // receive file name/path
    std::string filePath;
    filePath = CHAOS_FILE_PATH; // defined macro directing to <pathToLib>/ChaosAndFractal_Lib/chaos_files
    switch (fileNumber) {
        case 1: {
            filePath += "Baum_3d_1.lin";
            break;
        }
        case 2: {
            filePath += "Baum_3d_2.lin";
            break;
        }
        case 3: {
            filePath += "Busch_3d_2.lin";
            break;
        }
        case 4: {
            filePath += "Busch_3d_2.lin";
            break;
        }
        case 5: {
            filePath += "Sierpinski_pyramide_3d.lin";
            break;
        }
        default: {
            filePath += "Hilbert_kurve_3d.lin";
            break;
        }
    }

    // create and parse *.lin file
    window.setLSystemParams(filePath);

    //window.setCamera(MyWindow::CameraType::NONE);
    //window.setCamera(MyWindow::CameraType::STATIC_X_AXIS);
    //window.setCamera(MyWindow::CameraType::STATIC_Y_AXIS);
    //window.setCamera(MyWindow::CameraType::STATIC_Z_AXIS);
    window.setCamera(MyWindow::CameraType::ROTATION); // default value, you propably want to use this
    // set draw type
    // default: 0 - draw after each key-input
    //window.setMaxFPS(60.f);

    // set first clear color
    // I don't know why the first 'clear' within function MyWindow::draw does nothing....
    window.clear();

// start drawing
    // function returns when the "esc-key" is pressed
    return window.startDrawing();
}
