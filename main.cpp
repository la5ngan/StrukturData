#include "menu.cpp"
#include "parent.h"
#include "relation.h"
#include "child.h"

int main(int argc, char const *argv[]) {
	// List Parent & Child
	listParent daftarAngkutan;
	createList(daftarAngkutan);
	listChild daftarDaerah;
	createList(daftarDaerah);
	listRel Relation;
	createList(Relation);

	int choice;
	do {
		system("clear");
		printBanner();
		cout << endl
			<< " [1] Create" << endl
			<< " [2] Read" << endl
			<< " [3] Update" << endl
			<< " [4] Delete" << endl
			<< " [5] Exit" << endl << endl
			<< " [*] Enter your choice and press <enter>: ";
		cin >> choice;

		switch (choice) {
			case 1:
				showMenu("create", daftarAngkutan, daftarDaerah, Relation);
				break;

			case 2:
				showMenu("read", daftarAngkutan, daftarDaerah, Relation);
				break;

			case 3:
				showMenu("update", daftarAngkutan, daftarDaerah, Relation);
				break;

			case 4:
				showMenu("delete", daftarAngkutan, daftarDaerah, Relation);
				break;
		}
	} while (choice != 5);

	return 0;
}
