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

TEST(SplayTreeLib, TestSplayInsertWithoutData) {
	SplayTree* tree = new SplayTree();
	ASSERT_TRUE(tree->ShowString() == "");
}

TEST(SplayTreeLib, TestSplayInsertLeft) {
	SplayTree* tree = new SplayTree();
	tree->Insert(1);
	tree->Insert(2);
	tree->Insert(3);
	tree->Insert(4);
	tree->Insert(5);
	ASSERT_TRUE(tree->ShowString() == "5 4 3 2 1");
}

TEST(SplayTreeLib, TestSplayInsertRight) {
	SplayTree* tree = new SplayTree();
	tree->Insert(5);
	tree->Insert(4);
	tree->Insert(3);
	tree->Insert(2);
	tree->Insert(1);
	ASSERT_TRUE(tree->ShowString() == "1 2 3 4 5");
}

TEST(SplayTreeLib, TestSplayRightRotate) {
	SplayTree* tree = PreGeneratedSplayTree();
	tree->RightRotate(tree->root);
	ASSERT_TRUE(tree->ShowString() == "7 3 20 42 22 39 87");
}

TEST(SplayTreeLib, TestSplayLeftRotate) {
	SplayTree* tree = PreGeneratedSplayTree();
	tree->LeftRotate(tree->root);
	ASSERT_TRUE(tree->ShowString() == "42 20 7 3 22 39 87");
}

TEST(SplayTreeLib, TestSplayZagZag) {
	SplayTree* tree = PreGeneratedSplayTree();
	tree->Splay(tree->root->right->right);
	ASSERT_TRUE(tree->ShowString() == "87 42 20 7 3 22 39");
}

TEST(SplayTreeLib, TestSplayZigZig) {
	SplayTree* tree = PreGeneratedSplayTree();
	tree->Splay(tree->root->left->left);
	ASSERT_TRUE(tree->ShowString() == "3 7 20 42 22 39 87");
}

TEST(SplayTreeLib, TestSplayZigZag) {
	SplayTree* tree = PreGeneratedSplayTree();
	tree->Splay(tree->root->right->left);
	ASSERT_TRUE(tree->ShowString() == "22 20 7 3 42 39 87");
}

TEST(SplayTreeLib, TestSplayZagZig) {
	SplayTree* tree = PreGeneratedSplayTree();
	tree->Insert(100);
	tree->Splay(tree->root->left->right);
	ASSERT_TRUE(tree->ShowString() == "87 20 7 3 42 22 39 100");
}

TEST(SplayTreeLib, TestSplaySearch) {
	SplayTree* tree = PreGeneratedSplayTree();
	tree->Search(7);
	ASSERT_TRUE(tree->ShowString() == "7 3 20 42 22 39 87");
}

TEST(SplayTreeLib, TestSplaySearchWithoutData) {
	SplayTree* tree = new SplayTree();
	tree->Search(2);
	ASSERT_TRUE(tree->ShowString() == "");
}

TEST(SplayTreeLib, TestSplayDelete) {
	SplayTree* tree = PreGeneratedSplayTree();
	tree->Delete(42);
	ASSERT_TRUE(tree->ShowString() == "39 22 20 7 3 87");
}

TEST(SplayTreeLib, TestSplayDeleteWithoutData) {
	SplayTree* tree = new SplayTree();
	tree->Delete(2);
	ASSERT_TRUE(tree->ShowString() == "");
}

TEST(SplayTreeLib, TestSplayDeleteLeaf) {
	SplayTree* tree = PreGeneratedSplayTree();
	tree->Delete(39);
	ASSERT_TRUE(tree->ShowString() == "22 20 7 3 42 87");
}

TEST(SplayTreeLib, TestSplayDeleteRoot) {
	SplayTree* tree = PreGeneratedSplayTree();
	tree->Delete(20);
	ASSERT_TRUE(tree->ShowString() == "7 3 42 22 39 87");
}

TEST(SplayTreeLib, TestSplayProcess) {
	SplayTree* tree = PreGeneratedSplayTree();
	ASSERT_TRUE(tree->ShowString() == "20 7 3 42 22 39 87");
	tree->Insert(10);
	ASSERT_TRUE(tree->ShowString() == "10 7 3 20 42 22 39 87");
	tree->Search(42);
	ASSERT_TRUE(tree->ShowString() == "42 20 10 7 3 22 39 87");
	tree->Delete(22);
	ASSERT_TRUE(tree->ShowString() == "20 10 7 3 42 39 87");
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