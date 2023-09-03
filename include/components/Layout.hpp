#ifndef LAYOUT_HPP
#define LAYOUT_HPP
#include <components/Object.hpp>
#include <storage/Vector.hpp>

/*
 * Saat ini, window nggak punya layout oleh karena itu kita harus membuat 
 * layout  menggunakan fungsi ImGui atau menggunakan ImGui::SameLine() untuk 
 * menata letak untuk komponen-komponen yang ada. 
 * 
 * Implementasikan Layout pada BaseWindow. BaseWindow membutuhkan sebuah 
 * layout di mana layout tersebut dapat berisi layout-layout lainnya. 
 * 
 * Dengan itu, maka BaseWindow sekarang tidak memiliki m_components, sebagai 
 * gantinya kita akan menggantinya menjadi m_layout di mana itu adalah class Layout, 
 * base dari semua Layout. Layout lah yang akan memiliki m_components. 
 * 
 * Selain memiliki m_components, class Layout juga harus mempunyai m_layouts. Kita 
 * harus memungkinkan ada Layout. Meski dalam Layout bisa terdapat Layout lagi, 
 * tetapi BaseWindow hanya boleh mempunyai satu Layout.
 * 
 * Diambil dari: Deksripsi Task Jira.
 */

namespace Tridme {
  namespace UI {
    class Layout {
      public: 
        Layout();
        ~Layout();

        virtual void render();
        virtual void addComponent(Object* obj);
        virtual void addLayout(Layout* layout);
        virtual void removeComponent(Object* obj);
        virtual void removeLayout(Layout* layout);
        virtual void clearComponents();
        virtual void clearLayouts();
      
      private:
        Storage::Vector<std::string> m_ids;
        Storage::Vector<Object*>     m_components;
        Storage::Vector<Layout*>     m_layouts;
    };
  };
};

#endif 