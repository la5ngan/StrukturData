#include "menu.h"

void addData(string x, listParent &LP, listChild &LC, listRel &LR) {
	if (x == "angkutan") {
		do {
			system("clear");
			cin.ignore();
			cout << "[ ADD DATAS (Angkutan)]" << endl;
			cout << "> Plat Nomor: "; getline(cin, angkutan.kode);
			cout << "> Nama Angkutan: "; getline(cin, angkutan.nama);

			if (findElm(LP, angkutan.kode) == false) {
				adrParent P = allocate(angkutan);
				insertFirst(LP, P);
			} else cout << endl << "[-] Duplicate data.." << endl;

			cout << endl << "[*] Add data, again? [y/t]: "; cin >> repeat;
		} while (repeat != 't' && repeat != 'T');
	} else if (x == "daerah") {
		do {
			system("clear");
			cin.ignore();
			cout << "[ ADD DATA (Daerah)]" << endl;
			cout << "> Nama Daerah: "; getline(cin, daerah);

			adrChild srcDaerah = findElm(LC, daerah);
			if (srcDaerah == false) {
				insertSort(LC, allocate(daerah));
			} else cout << endl << "[-] Duplicate data.." << endl;

			cout << endl << "[*] Add data, again? [y/t]: "; cin >> repeat;
		} while (repeat != 't' && repeat != 'T');
	} else if (x == "relasi") {
		do {
			system("clear");
			cin.ignore();
			cout << " [ ADD NEW RELATION - From Parent to Child ]" << endl << endl;

			cout << "[*] Datas Parent (Angkutan)" << endl;
			printInfo(LP);
			cout << endl;

			cout << "[*] Datas Child (Daerah)" << endl;
			printInfo(LC);
			cout << endl;

			cout << "> Kode Angkutan: "; getline(cin, angkutan.kode);
			cout << "> Nama Daerah: "; getline(cin, daerah);

			adrParent srcParent = findElm(LP, angkutan.kode);
			adrChild srcChild = findElm(LC, daerah);

			if (srcParent != NULL && srcChild != NULL) {
				adrRel datas = allocate(srcParent, srcChild);
				insertLast(LR, datas);
			} else cout << endl << "[-] Data not found.." << endl;

			cout << endl << "[*] Add data, again? [y/t]: "; cin >> repeat;
		} while (repeat != 't' && repeat != 'T');
	}
}

void showDatas(string x, listParent &LP, listChild &LC, listRel &LR) {
	if (x == "all") {
		system("clear");
		cin.ignore();

		cout << " [ SHOW ALL DATA ] " << endl << endl;
		cout << "[*] Data Angkutan" << endl;
		printInfo(LP); cout << endl;

		cout << "[*] Data Daerah" << endl;
		printInfo(LC); cout << endl;

		cout << "[*] Data Relasi" << endl;
		printInfo(LR);

		cin.ignore().get();
	} else if (x == "daerah") {
		system("clear");
		cin.ignore();

		cout << " [ SHOW DATA PARENT (Angkutan) - search by child (Daerah)]" << endl;
		cout << "> Nama Daerah: "; getline(cin, daerah);

		adrChild srcChild = findElm(LC, daerah);
		if (srcChild == NULL) cout << endl << "[-] Datas not found.." << endl;
		else if (first(LR) != NULL) {
			adrRel P = first(LR);
			while (next(P) != first(LR)) {
				if (child(P) == srcChild) {
					cout << "-> " << (info(parent(P)).kode << " | " << info(parent(P)).nama << endl;
				}
				P = next(P);
			}

			if (child(P) == srcChild) {
				cout << "-> " << info(parent(P)).kode << " | " << info(parent(P)).nama << endl;
			}
		}

		cin.ignore().get();
	} else if (x == "angkutan") {
		system("clear");
		cin.ignore();

		cout << " [ SHOW DATA CHILD (Daerah) - search by parent (Angkutan)]" << endl;
		cout << "> Kode Angkutan: "; getline(cin, angkutan.kode);

		adrParent srcParent = findElm(LP, angkutan.kode);
		if (srcParent == NULL) cout << endl << "[-] Data not found.." << endl;
		else if (first(LR) != NULL) {
			adrRel P = first(LR);
			while (next(P) != first(LR)) {
				if (parent(P) == srcParent) {
					cout << "-> " << info(child(P)) << endl;
				}
				P = next(P);
			}

			if (parent(P) == srcParent) {
				cout << "-> " << info(parent(P)) << endl;
			}
		}
		cin.ignore().get();
	} else if (x == "minmax") {
		system("clear");
		cin.ignore();

		cout << " [ SHOW THE EASIEST AND MOST DIFFICULT DATA CHILD (Daerah) ] " << endl;
		adrChild C = first(LC); int max = 0, min = 1, i;
		while (C != NULL) {
			adrRelation Q = first(LR);
			i = 0;
			while (next(Q) != first(LR))
            {
				(child(Q) != C) ? : i++;
				Q = next(Q);
			} (child(Q) != C) ? : i++;

			if (i > max) max = i;
			if (i != 0 && i < min) min = i;
			C = next(C);
		}

		C = first(LC); string MIN, MAX;
		while (C != NULL) {
			adrRelation Q = first(LR); i = 0;
			while (next(Q) != first(LR)) {
				(child(Q) != C) ? : i++;
				Q = next(Q);
			} (child(Q) != C) ? : i++;

			if (i == max) MAX = C->info;
			if (i == min) MIN = C->info;

			C = next(C);
		}

		if (MIN != MAX) {
			cout << "[*] Difficult: " << MIN << " | Easiest: " << MAX << endl;
		}
		cin.ignore().get();
	}
}

void updateData(string x, listParent &LP, listChild &LC, listRel &LR) {
	if (x == "angkutan") {
		do {
			system("clear");
			cin.ignore();

			cout << " [ UPDATE DATAS PARENT (Angkutan) ]" << endl << endl;
			cout << "> Plat Nomor: "; getline(cin, angkutan.kode);

			adrParent srcParent = findElm(LP, angkutan.kode);
			if (srcParent != NULL) {
				system("clear");
				cout << " [ NEW DATAS ] " << endl << endl;
				cout << "> Plat Nomor: "; getline(cin, srcParent->info.kode);
				cout << "> Nama Angkutan: "; getline(cin, srcParent->info.nama);
			} else cout << endl << "[-] Datas not found.." << endl;

			cout << "[*] Update datas, again? [y/t]: "; cin >> repeat;
		} while (repeat != 't' && repeat != 'T');
	} else if (x == "daerah") {
		do {
			system("clear");
			cin.ignore();

			cout << " [ UPDATE DATA PARENT (Angkutan) ]" << endl << endl;
			cout << "> Masukkan Nama Daerah: "; getline(cin, daerah);

			adrChild srcChild = findElm(LC, daerah);
			if (srcChild != NULL) {
				system("clear");
				cout << " [ NEW DATA ] " << endl << endl;
				cout << "> Nama Daerah: "; getline(cin, srcChild->info);
			} else cout << endl << "[-] Data not found.." << endl;

			cout << "[*] Update datas, again? [y/t]: "; cin >> repeat;
		} while (repeat != 't' && repeat != 'T');
	}
}

void deleteData(string x, listParent &LP, listChild &LC, listRel &LR)
{
	system("clear");
	cin.ignore();
	if (x == "angkutan") {
		cout << "> Plat Nomor: "; getline(cin, angkutan.kode);
		adrParent srcAngkutan = findElm(LP, angkutan.kode);

		if (srcAngkutan != NULL) {
			if (findParentRel(LR, srcAngkutan))
				deleteRelationParent(LR, srcAngkutan);
			deleteParent(LP, srcAngkutan);
		}
	} else if (x == "daerah") {
		cout << "> Daerah: "; getline(cin, daerah);
		adrChild srcDaerah = findElm(LC, daerah);

		if (srcDaerah != NULL) {
			if (findChildRel(LR, srcDaerah))
				deleteRelationChild(LR, srcDaerah);
			deleteChild(LC, srcDaerah);
		}
	}
}

void showMenu(string x, listParent &LP, listChild &LC, listRel &LR)
{
	if (x == "create") {
		system("clear");
		do {
			system("clear");
			cout << " [ CREATE DATA ]" << endl;
			cout << endl
			     << " [1] Add data (Angkutan)" << endl
			     << " [2] Add data (Daerah)" << endl
			     << " [3] Add new Relation" << endl
			     << " [4] Back to dashboard menu" << endl << endl
			     << " [*] Enter your choice and press <enter>: ";
			cin >> choice;

			switch (choice) {
				case 1:
					addData("angkutan", LP, LC, LR); // insert sort
					break;

				case 2:
					addData("daerah", LP, LC, LR); // insert last
					break;

				case 3:
					addDatas("relasi", LP, LC, LR); // insert first
					break;
			}
		} while (choice != 4);
	} else if (x == "read") {
		system("clear");
		do {
			system("clear");
			cout << " [ SHOW DATA ]" << endl;
			cout << endl
			     << " [1] Show all data" << endl
			     << " [2] Show data (Daerah) - (search by Angkutan)" << endl
			     << " [3] Show data (Angkutan) - (search by Daerah)" << endl
			     << " [4] Show the easiest and most difficult datas of the transport area." << endl
			     << " [5] Back to dashboard menu" << endl << endl
			     << " [*] Enter your choice and press <enter>: ";
			cin >> choice;

			switch (choice) {
				case 1:
					showData("all", LP, LC, LR);
					break;

				case 2:
					showData("angkutan", LP, LC, LR);
					break;

				case 3:
					showData("daerah", LP, LC, LR);
					break;

				case 4:
					showData("minmax", LP, LC, LR);
					break;
			}
		} while (choice != 5);

	} else if (x == "update") {
		system("clear");
		do {
			system("clear");
			cout << " [ UPDATE DATA ]" << endl;
			cout << endl
			     << " [1] Update angkutan" << endl
			     << " [2] Update daerah" << endl
			     << " [3] Back to dashboard menu" << endl << endl
			     << " [*] Enter your choice and press <enter>: ";
			cin >> choice;

			switch (choice) {
				case 1:
					updateData("angkutan", LP, LC, LR);
					break;

				case 2:
					updateData("daerah", LP, LC, LR);
					break;
			}
		} while (choice != 3);

	} else if (x == "delete") {
		do {
			system("clear");
			cout << " [ DELETE DATA ] " << endl;
			cout << endl
			     << " [1] Delete Angkutan" << endl
			     << " [2] Delete Daerah" << endl
			     << " [3] Back to dashboard menu" << endl << endl
			     << " [*] Enter your choice and press <enter>: ";
			cin >> choice;

			switch (choice) {
				case 1:
					deleteData("angkutan", LP, LC, LR);
					break;

				case 2:
					deleteData("daerah", LP, LC, LR);
					break;
			}
		} while (choice != 3);
	}
}
