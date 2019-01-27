#include<iostream>
#include<memory>

int main(){
  //const std::unique_ptr<float> test_ptr1 = std::unique_ptr<float>{new float (3.14)};
  // std::unique_ptr<float> test_ptr1 = std::unique_ptr<float>{new float (3.14)}; // Ohne das const koennte ich dem unique_ptr eine neue Adresse im Verlauf des Programms uebergeben!
  // das const hier setzt den unique_ptr auf const. Also der Pointer an sich kann nicht umgesetzt werden.
  // Im Endeffekt ist ein unique_ptr nichts anderes als ein Wrapper-Objekt um einen normalen Pointer. Deshalb setze ich hiermit nur den unique_ptr auf const!
  // Deshalb kann ich in Zeile 12 den Wert hinter dem Pointer nach belieben veraendern!

  const std::unique_ptr<float> test_ptr1;
  test_ptr1 = std::unique_ptr<float>{new float (3.14)};

  std::cout << "this is the value of test_ptr1: " << *test_ptr1 << std::endl;

  *test_ptr1 = 10.221;
  std::cout << "changed the value of the unique_ptr: " << *test_ptr1 << std::endl;
  // Reassignment der Adresse auf den der unique_ptr zeigen soll
  test_ptr1 = std::unique_ptr<float>{new float (3.14)}; // Geht nicht, da ich die Adresse des unique_ptr auf const gesetzt habe!


  // Setze den Wert hinter dem Pointer auf const:
  std::unique_ptr<const float> test_ptr2 = std::unique_ptr<const float>{new const float (3.14)};
  std::cout << "this is the value of test_ptr2: " << *test_ptr2 << std::endl;
  /*
  *test_ptr2 = 666;
  std::cout << "this is the value of test_ptr2 after reassignment of the value: "  << test_ptr2 << std::endl;
  */

  return 0;
}
