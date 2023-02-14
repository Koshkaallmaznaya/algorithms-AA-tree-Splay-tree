#include "pch.h"
#include <random>
#include <stdlib.h>
using namespace std;

AATree* PreGeneratedAATree() { //заранее сделанное дерево для использования в разных тестах
	AATree* tree = new AATree();
	AANode* last = tree->Insert(3);
	last = tree->Insert(39);
	last = tree->Insert(87);
	last = tree->Insert(7);
	last = tree->Insert(22);
	last = tree->Insert(42);
	last = tree->Insert(20);
	return tree;
}

TEST(AATreeLib, TestAAInsertBig) {
	AATree* tree = new AATree();
	for (int i = 0; i < 100000; i++) {
		tree->Insert(i);
	}
}

TEST(AATreeLib, TestAARight) {
	AATree* tree = new AATree();
	tree->Insert(1);
	tree->Insert(2);
	tree->Insert(3);
	tree->Insert(4);
	tree->Insert(5);
	cout << tree->ShowString();
}

TEST(AATreeLib, TestAALeft) {
	AATree* tree = new AATree();
	tree->Insert(5);
	tree->Insert(4);
	tree->Insert(3);
	tree->Insert(2);
	tree->Insert(1);
	tree->Show("", true);
}

TEST(AATreeLib, TestAASearchWithData) {
	AATree* tree = PreGeneratedAATree();
	tree->Show("", true);
	tree->Search(7);
	tree->Show("", true);
}

TEST(AATreeLib, TestAASearchWithoutData) {
	AATree* tree = PreGeneratedAATree();
	tree->Show("", true);
	tree->Search(2);
	tree->Show("", true);
}

TEST(AATreeLib, TestAADeleteWithData) {
	AATree* tree = PreGeneratedAATree();
	tree->Show("", true);
	tree->Delete(42);
	tree->Show("", true);
}

TEST(AATreeLib, TestAADeleteWithoutData) {
	AATree* tree = PreGeneratedAATree();
	tree->Show("", true);
	tree->Delete(2);
	tree->Show("", true);
}

TEST(AATreeLib, TestAADeleteLeaf) {
	AATree* tree = PreGeneratedAATree();
	tree->Show("", true);
	tree->Delete(39);
	tree->Show("", true);
}

TEST(AATreeLib, TestAADeleteRoot) {
	AATree* tree = PreGeneratedAATree();
	tree->Show("", true);
	tree->Delete(20);
	tree->Show("", true);
}

TEST(AATreeLib, TestAAProcess) {
	AATree* tree = PreGeneratedAATree();
	cout << tree->ShowString();
	tree->Insert(10);
	tree->Search(42);
	tree->Delete(22);
	cout << tree->ShowString();
	tree->Show("", true);
}

//далее идут тесты для исследования
//тесты на скорость вставки большого количества чисел
TEST(AATreeLib, TestAAInsertBig3) {
	AATree* tree = new AATree();
	for (int i = 0; i < 1000; i++) {
		tree->Insert(i);
	}
}

TEST(AATreeLib, TestAAInsertBig4) {
	AATree* tree = new AATree();
	for (int i = 0; i < 10000; i++) {
		tree->Insert(i);
	}
}

TEST(AATreeLib, TestAAInsertBig5) {
	AATree* tree = new AATree();
	for (int i = 0; i < 100000; i++) {
		tree->Insert(i);
	}
}

TEST(AATreeLib, TestAAInsertBig6) {
	AATree* tree = new AATree();
	for (int i = 0; i < 1000000; i++) {
		tree->Insert(i);
	}
}

TEST(AATreeLib, TestAAInsertBig7) {
	AATree* tree = new AATree();
	for (int i = 0; i < 10000000; i++) {
		tree->Insert(i);
	}
}

//тесты на скорость вставки 10^6 и удаления большого количества чисел
TEST(AATreeLib, TestAAInsertDeleteBig3) {
	AATree* tree = new AATree();
	for (int i = 0; i < 1000000; i++) {
		tree->Insert(i);
	}
	for (int i = 0; i < 1000; i++) {
		tree->Delete(i);
	}
}

TEST(AATreeLib, TestAAInsertDeleteBig4) {
	AATree* tree = new AATree();
	for (int i = 0; i < 1000000; i++) {
		tree->Insert(i);
	}
	for (int i = 0; i < 10000; i++) {
		tree->Delete(i);
	}
}

TEST(AATreeLib, TestAAInsertDeleteBig5) {
	AATree* tree = new AATree();
	for (int i = 0; i < 1000000; i++) {
		tree->Insert(i);
	}
	for (int i = 0; i < 100000; i++) {
		tree->Delete(i);
	}
}

TEST(AATreeLib, TestAAInsertDeleteBig6) {
	AATree* tree = new AATree();
	for (int i = 0; i < 1000000; i++) {
		tree->Insert(i);
	}
	for (int i = 0; i < 1000000; i++) {
		tree->Delete(i);
	}
}

//тесты на скорость вставки рандомных чисел
TEST(AATreeLib, TestAAInsertRandom7) {
	AATree* tree = new AATree();
	for (int i = 0; i < 10000000; i++) {
		tree->Insert(rand());
	}
}

TEST(AATreeLib, TestAAInsertRandom6) {
	AATree* tree = new AATree();
	for (int i = 0; i < 1000000; i++) {
		tree->Insert(rand());
	}
}

TEST(AATreeLib, TestAAInsertRandom5) {
	AATree* tree = new AATree();
	for (int i = 0; i < 100000; i++) {
		tree->Insert(rand());
	}
}

TEST(AATreeLib, TestAAInsertRandom4) {
	AATree* tree = new AATree();
	for (int i = 0; i < 10000; i++) {
		tree->Insert(rand());
	}
}