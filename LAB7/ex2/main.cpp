#include "TreeTemplate.h"

int main()
{
	srand(time(NULL));

	//arbore vid, fara radacina
	TreeTemplate<int> *tree = new TreeTemplate<int>;

	//adaug radacina
	tree->add_node(0); //sau nullptr

	//fiul radacinii
	tree->add_node(&tree->get_node(0));

	//3 nepoti ai radacinii
	tree->add_node(&tree->get_node(&tree->get_node(0)));
	tree->add_node(&tree->get_node(&tree->get_node(0)));
	tree->add_node(&tree->get_node(&tree->get_node(0)));
	//inserez la o pozitie specificata (2), inca un nepot
	tree->insert_node(&tree->get_node(&tree->get_node(0)), 2);

	cout << "Numarul de nepoti ai radacinii: ";
	cout << tree->count(&tree->get_node(&tree->get_node(0))); 
	cout << '\n';

	//caut 21 in tot arborele
	if (tree->find(21, callback1)) cout << "21 este in arbore.";
	else cout << "21 nu este in arbore";
	cout << '\n';

	cout << "Nepotii radacinii sortati descrescator: ";
	tree->sort(&tree->get_node(&tree->get_node(0)), callback2);
	tree->print(&tree->get_node(&tree->get_node(0)));
	cout << '\n';

	cout << "Nepotii radacinii sortati crescator: ";
	tree->sort(&tree->get_node(&tree->get_node(0)), nullptr); //fara functia de callback, se ia defaultul
	tree->print(&tree->get_node(&tree->get_node(0)));
	cout << '\n';
	return 0;
}