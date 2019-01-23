#include<iostream>
#include<vector> // STL -> vector, dequeue
#include<stdlib.h> // rand
#include<algorithm>

struct data{
  unsigned int val1;
  int val2;
};

int main(){

  // Erstelle vector aus STL
  std::vector<data> stored_data; // beliebige Groesse
  //std::vector<data> stored_data_size_10(10); // groesse festgelegt -> erstellt Vektor mit 10 leeren elementen (Alles mit 0 initialisiert)
  for (unsigned int i = 0; i < 10; i++){
    stored_data.push_back(data{i, rand()});
    //stored_data_size_10[i] = data{i, rand()};
  }

  std::for_each(stored_data.begin(), stored_data.end(), [](data d){std::cout << d.val1 << " " << d.val2 << std::endl;});
  //std::for_each(stored_data_size_10.begin(), stored_data_size_10.end(), [](data d){std::cout << d.val1 << " " << d.val2 << std::endl;});

  /*
  // Alternative ('Initialisierungsliste'):
  std::vector<data> container;
  data init_list[10]; // Initialisierungsliste
  for (unsigned int i = 0; i<10; i++){
    init_list[i] = data{i, rand()};
    container.push_back(init_list[i]);
  }

  std::for_each(container.begin(), container.end(), [](data d){std::cout << d.val1 << " " << d.val2 << std::endl;});
  */

  // Sortieren nach val2:
  std::sort(stored_data.begin(), stored_data.end(), [](data d, data e){return d.val2 < e.val2;});
  std::for_each(stored_data.begin(), stored_data.end(), [](data d){std::cout << d.val1 << " " << d.val2 << std::endl;});

  // Veraendere den val2 nach val1*val1
  //std::for_each(stored_data.begin(), stored_data.end(), [](data d){d.val2 = d.val1*d.val1; std::cout << d.val1 << " " << d.val2 << std::endl; });
  /*
   * das hier geht nicht, da ich der Lambdafunktion nicht erlaubt habe die Werte der uebergebenen Variablen zu veraendern!
  std::for_each(stored_data.begin(), stored_data.end(), [](data d){d.val2 = d.val1*d.val1; });
  std::for_each(stored_data.begin(), stored_data.end(), [](data d){std::cout << d.val1 << " " << d.val2 << std::endl;});
  */
  std::for_each(stored_data.begin(), stored_data.end(), [](data &d){d.val2 = d.val1*d.val1;});
  // std::for_each(stored_data.begin(), stored_data.end(), [](data d){d = [](data d)->data{d.val2 = d.val1*d.val1; return d;};}); // TODO: Geht nicht-warum?
  std::for_each(stored_data.begin(), stored_data.end(), [](data d){std::cout << d.val1 << " " << d.val2 << std::endl;});



  // Captures
  int val {42};
  // Aufgabe 1:
  std::for_each(stored_data.begin(), stored_data.end(), [&val](data &d){d.val2 = val;});
  std::for_each(stored_data.begin(), stored_data.end(), [](data d){std::cout << d.val1 << " " << d.val2 << std::endl; });
  // Aufgabe 2:
  std::for_each(stored_data.begin(), stored_data.end(), [=](data &d)mutable{d.val2 = val; val++;});                         // bleibt bei val=42 global
  //std::for_each(stored_data.begin(), stored_data.end(), [&](data &d){d.val2 = val; val++;});                                // inkrementiert val global
  std::for_each(stored_data.begin(), stored_data.end(), [](data d){std::cout << d.val1 << " " << d.val2 << std::endl; });
  std::cout << "this is val: " << val << std::endl;


  return 0;
}
