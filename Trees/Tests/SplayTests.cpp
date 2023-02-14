#include "pch.h"
#include <random>
#include <stdlib.h>
using namespace std;

SplayTree* PreGeneratedSplayTree() { //заранее сделанное дерево для использования в разных тестах
	SplayTree* tree = new SplayTree();
	tree->Insert(3);
	tree->Insert(39);
	tree->Insert(87);
	tree->Insert(7);
	tree->Insert(22);
	tree->Insert(42);
	tree->Insert(20);
	return tree;
}

TEST(SplayTreeLib, TestSplayInsertBig) {
	SplayTree* tree = new SplayTree();
	for (int i = 0; i < 100000; i++) {
		tree->Insert(i);
	}
}

TEST(SplayTreeLib, TestSplayRight) {
	SplayTree* tree = new SplayTree();
	tree->Insert(1);
	tree->Insert(2);
	tree->Insert(3);
	tree->Insert(4);
	tree->Insert(5);
	tree->Show("", true);
}

TEST(SplayTreeLib, TestSplayLeft) {
	SplayTree* tree = new SplayTree();
	tree->Insert(5);
	tree->Insert(4);
	tree->Insert(3);
	tree->Insert(2);
	tree->Insert(1);
	tree->Show("", true);
}

TEST(SplayTreeLib, TestSplaySearchWithData) {
	SplayTree* tree = PreGeneratedSplayTree();
	tree->Show("", true);
	tree->Search(7);
	tree->Show("", true);
}

TEST(SplayTreeLib, TestSplaySearchWithoutData) {
	SplayTree* tree = PreGeneratedSplayTree();
	tree->Show("", true);
	tree->Search(2);
	tree->Show("", true);
}

TEST(SplayTreeLib, TestSplayDeleteWithData) {
	SplayTree* tree = PreGeneratedSplayTree();
	tree->Show("", true);
	tree->Delete(42);
	tree->Show("", true);
}

TEST(SplayTreeLib, TestSplayDeleteWithoutData) {
	SplayTree* tree = PreGeneratedSplayTree();
	tree->Show("", true);
	tree->Delete(2);
	tree->Show("", true);
}

TEST(SplayTreeLib, TestSplayDeleteLeaf) {
	SplayTree* tree = PreGeneratedSplayTree();
	tree->Show("", true);
	tree->Delete(39);
	tree->Show("", true);
}

TEST(SplayTreeLib, TestSplayDeleteRoot) {
	SplayTree* tree = PreGeneratedSplayTree();
	tree->Show("", true);
	tree->Delete(20);
	tree->Show("", true);
}

TEST(SplayTreeLib, TestSplayProcess) {
	SplayTree* tree = PreGeneratedSplayTree();
	tree->Insert(10);
	tree->Search(42);
	tree->Delete(22);
	cout << tree->ShowString();
	tree->Show("", true);
	//ASSERT_TRUE(ShowString(tree->GetRoot()) == "20 10 7 3 42 39 87");
}

//далее идут тесты для исследования
//тесты на скорость вставки большого количества чисел
TEST(SplayTreeLib, TestSplayInsertBig3) {
	SplayTree* tree = new SplayTree();
	for (int i = 0; i < 1000; i++) {
		tree->Insert(i);
	}
}

TEST(SplayTreeLib, TestSplayInsertBig4) {
	SplayTree* tree = new SplayTree();
	for (int i = 0; i < 10000; i++) {
		tree->Insert(i);
	}
}

TEST(SplayTreeLib, TestSplayInsertBig5) {
	SplayTree* tree = new SplayTree();
	for (int i = 0; i < 100000; i++) {
		tree->Insert(i);
	}
}

TEST(SplayTreeLib, TestSplayInsertBig6) {
	SplayTree* tree = new SplayTree();
	for (int i = 0; i < 1000000; i++) {
		tree->Insert(i);
	}
}

TEST(SplayTreeLib, TestSplayInsertBig7) {
	SplayTree* tree = new SplayTree();
	for (int i = 0; i < 10000000; i++) {
		tree->Insert(i);
	}
}

//тесты на скорость вставки 10^6 и удаления большого количества чисел
TEST(SplayTreeLib, TestSplayInsertDeleteBig3) {
	SplayTree* tree = new SplayTree();
	for (int i = 0; i < 1000000; i++) {
		tree->Insert(i);
	}
	for (int i = 0; i < 1000; i++) {
		tree->Delete(i);
	}
}

TEST(SplayTreeLib, TestSplayInsertDeleteBig4) {
	SplayTree* tree = new SplayTree();
	for (int i = 0; i < 1000000; i++) {
		tree->Insert(i);
	}
	for (int i = 0; i < 10000; i++) {
		tree->Delete(i);
	}
}

TEST(SplayTreeLib, TestSplayInsertDeleteBig5) {
	SplayTree* tree = new SplayTree();
	for (int i = 0; i < 1000000; i++) {
		tree->Insert(i);
	}
	for (int i = 0; i < 100000; i++) {
		tree->Delete(i);
	}
}

TEST(SplayTreeLib, TestSplayInsertDeleteBig6) {
	SplayTree* tree = new SplayTree();
	for (int i = 0; i < 1000000; i++) {
		tree->Insert(i);
	}
	for (int i = 0; i < 1000000; i++) {
		tree->Delete(i);
	}
}

//тесты на скорость вставки рандомных чисел
TEST(SplayTreeLib, TestSplayInsertRandom7) {
	SplayTree* tree = new SplayTree();
	for (int i = 0; i < 10000000; i++) {
		tree->Insert(rand());
	}
}

TEST(SplayTreeLib, TestSplayInsertRandom6) {
	SplayTree* tree = new SplayTree();
	for (int i = 0; i < 1000000; i++) {
		tree->Insert(rand());
	}
}

TEST(SplayTreeLib, TestSplayInsertRandom5) {
	SplayTree* tree = new SplayTree();
	for (int i = 0; i < 100000; i++) {
		tree->Insert(rand());
	}
}

TEST(SplayTreeLib, TestSplayInsertRandom4) {
	SplayTree* tree = new SplayTree();
	for (int i = 0; i < 10000; i++) {
		tree->Insert(rand());
	}
}