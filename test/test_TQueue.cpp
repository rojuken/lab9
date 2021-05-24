#include "QueueList.h"

#include "../gtest/gtest.h"

TEST(TQueueList, can_create_stacklist)
{
	ASSERT_NO_THROW(TQueueList<int> A);
}

TEST(TQueueList, can_copy)
{
	TQueueList<int> A;
	A.Push(2);
	TQueueList<int> B(A);
	ASSERT_EQ(2, B.Get());
}

TEST(TQueueList, can_push)
{
	TQueueList<int> A;
	ASSERT_NO_THROW(A.Push(5));
}

TEST(TQueueList, can_get)
{
	TQueueList<int> A;
	A.Push(10);
	ASSERT_EQ(10, A.Get());
}

TEST(TQueueList, can_equate_stacklists)
{
	TQueueList<int> A;
	A.Push(2);
	TQueueList<int> B;
	B = A;
	ASSERT_EQ(2, B.Get());
}

TEST(TQueueList, check_is_empty)
{
	TQueueList<int> A;
	ASSERT_EQ(true, A.IsEmpty());
}

TEST(TQueueList, check_is_full)
{
	TQueueList<int> A;
	ASSERT_EQ(false, A.IsFull());
}

TEST(TQueueList, can_get_min_elem)
{
	TQueueList<int> A;
	A.Push(10);
	A.Push(2);
	A.Push(3);
	A.Push(4);

	ASSERT_EQ(2, A.MinElem());
}

TEST(TQueueList, can_get_max_elem)
{
	TQueueList<int> A;
	A.Push(1);
	A.Push(10);
	A.Push(2);
	A.Push(3);
	A.Push(4);

	ASSERT_EQ(10, A.MaxElem());
}

TEST(TQueueList, can_load_to_file)
{
	TQueueList<int> A;
	A.Push(1);
	A.Push(10);
	A.Push(2);
	A.Push(3);
	A.Push(4);
	ASSERT_NO_THROW(A.LoadToFile());

}