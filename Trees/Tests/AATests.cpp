#include "pch.h"
#include <random>
#include <stdlib.h>
using namespace std;

AATree* PreGeneratedAATree() { //заранее сделанное дерево для использования в разных тестах
	AATree* tree = new AATree();
	tree->Insert(3);
	tree->Insert(39);
	tree->Insert(87);
	tree->Insert(7);
	tree->Insert(22);
	tree->Insert(42);
	tree->Insert(20);
	return tree;
}

TEST(AATreeLib, TestAAInsertWithoutData) {
	AATree* tree = new AATree();
	ASSERT_TRUE(tree->ShowString() == "");
}

TEST(AATreeLib, TestAAInsert) {
	AATree* tree = new AATree();
	tree->Insert(1);
	tree->Insert(2);
	tree->Insert(3);
	tree->Insert(4);
	tree->Insert(5);
	ASSERT_TRUE(tree->ShowString() == "2 1 4 3 5");
}

TEST(AATreeLib, TestAASearchWithoutData) {
	AATree* tree = new AATree();
	tree->Search(2);
	ASSERT_TRUE(tree->ShowString() == "");
}

TEST(AATreeLib, TestAASearchWithData) {
	AATree* tree = PreGeneratedAATree();
	tree->Search(7);
	ASSERT_TRUE(tree->ShowString() == "7 3 39 20 22 42 87");
}

TEST(AATreeLib, TestAADelete) {
	AATree* tree = PreGeneratedAATree();
	tree->Delete(42);
	ASSERT_TRUE(tree->ShowString() == "7 3 39 20 22 87");
}

TEST(AATreeLib, TestAADeleteWithoutData) {
	AATree* tree = new AATree();
	tree->Delete(2);
	ASSERT_TRUE(tree->ShowString() == "");
}

TEST(AATreeLib, TestAADeleteLeaf) {
	AATree* tree = PreGeneratedAATree();
	tree->Delete(87);
	ASSERT_TRUE(tree->ShowString() == "7 3 39 20 22 42");
}

TEST(AATreeLib, TestAASkew) {
	AATree* tree = PreGeneratedAATree();
	tree->root->left->level = 4;
	tree->Skew(tree->root);
	ASSERT_TRUE(tree->ShowString() == "7 3 39 20 22 42 87");
	ASSERT_TRUE(tree->root->left->level = 3);
}

TEST(AATreeLib, TestAASplit) {
	AATree* tree = PreGeneratedAATree();
	tree->root->right->level = 4;
	tree->root->right->right->level = 4;
	tree->Split(tree->root);
	ASSERT_TRUE(tree->ShowString() == "7 3 39 20 22 42 87");
	ASSERT_TRUE(tree->root->right->level = 3);
	ASSERT_TRUE(tree->root->right->right->level = 2);
}

TEST(AATreeLib, TestAAProcess) {
	AATree* tree = PreGeneratedAATree();
	ASSERT_TRUE(tree->ShowString() == "7 3 39 20 22 42 87");
	tree->Insert(10);
	ASSERT_TRUE(tree->ShowString() == "20 7 3 10 39 22 42 87");
	tree->Search(42);
	ASSERT_TRUE(tree->ShowString() == "20 7 3 10 39 22 42 87");
	tree->Delete(22);
	ASSERT_TRUE(tree->ShowString() == "20 7 3 10 42 39 87");
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