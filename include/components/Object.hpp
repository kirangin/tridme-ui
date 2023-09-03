#ifndef OBJECT_HPP
#define OBJECT_HPP
#include <iostream>
#include <string>
#include <imgui.h>
#include <storage/Vector.hpp>
#include <storage/Vector2.hpp>
#include <core/Signal.hpp>
#include <unordered_map>
using namespace Tridme;
using namespace Tridme::Storage;

/*
 * Object adalah kelas abstrak yang merepresentasikan objek yang ada di dalam game.
 * Class ini erisi dasar-dasar elemen yang dibutuhkan dalam semua turunannya seperti 
 * posisi dan ukuran.
 * 
 * Cara kerjanya adalah setiap turunan dari kelas ini akan mengimplementasikan fungsi 
 * render yang akan menggambar objek tersebut ke layar menggunakan ImGui::Something.
 * 
 * Untuk mengambil input / event, kita akan menggunakan signal dan slot di mana object
 * akan mengeluarkan sinyal (misal: onClicked) dan akan dihandle oleh kelas lain yang
 * mengimplementasikan slot tersebut. See Signal.hpp / Signal.cpp
 */

namespace Tridme {
  namespace UI {
    enum TextAlign {
      CENTER,
      LEFT,
      RIGHT,
      JUSTIFY
    };

    class Object {
      public: 
        Object();
        ~Object();

        virtual void render() { }
        virtual std::string getType() const {
          return this->m_type;
        }

        void show();
        void hide();
        void setVisible(bool value);
        void setId(const std::string& id);
        std::string getId() const {
          return this->id;
        }

      protected:
        Vector2<int> size;
        Vector2<int> position;
        std::string  id;

        std::unordered_map<std::string, Storage::Vector<std::string>> componentIds;

        std::string m_type = "Object";
        bool m_isVisible = true;
    };
  };
};

#endif