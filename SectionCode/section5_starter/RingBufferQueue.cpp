#include "RingBufferQueue.h"
#include "testing/SimpleTest.h"

using namespace std;

const int DEFAULT_CAPACITY = 10;

/**
 * TODO: write a method comment
 */
RBQueue::RBQueue() {
    capacity = DEFAULT_CAPACITY;
    elements = new int[capacity];
    head = 0;
    size = 0;
}

/**
 * TODO: write a method comment
 */
RBQueue::~RBQueue() {
    delete[] elements;
}

/**
 * TODO: write a method comment
 */
void RBQueue::enqueue(int elem) {
    if (isFull()) {
        throw "Can't enqueue, queue is full";
    }
    elements[tail] = elem;
    tail = (tail + 1) % capacity;
    size++;
}

/**
 * TODO: write a method comment
 */
int RBQueue::dequeue() {
    if (isEmpty()) {
        throw "Can't dequeue, queue is empty";
    }
    int val = peek();
    head = (head + 1) % capacity;
    size--;
}

/**
 * TODO: write a method comment
 */
int RBQueue::peek() {
    if (isEmpty()) {
        throw "queue is empty";
    }
    return elements[head];
}

/**
 * TODO: write a method comment
 */
bool RBQueue::isEmpty() {
    return size == 0;
}

/**
 * TODO: write a method comment
 */
bool RBQueue::isFull() {
    // The following lines are just here to
    // disable compiler warnings and errors.
    // Delete these lines, then implement
    // this method.
    return size == capacity;
}

/**
 * TODO: write a method comment
 */
int RBQueue::size() {
    // The following lines are just here to
    // disable compiler warnings and errors.
    // Delete these lines, then implement
    // this method.
    return size;
}

/**
 * TODO: write a method comment
 */
ostream& operator<<(ostream& out, const RBQueue& queue) {
    (void) queue;
    return out;
}

/* Provided Tests Below This Line */

PROVIDED_TEST("Simple Example From Handout"){
    RBQueue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    EXPECT_EQUAL(q.peek(), 1);
    q.enqueue(4);
    q.enqueue(5);
    EXPECT(!q.isFull());
    EXPECT_EQUAL(q.dequeue(), 1);
    EXPECT_EQUAL(q.dequeue(), 2);
    EXPECT_EQUAL(q.peek(), 3);
    q.enqueue(6);
    EXPECT_EQUAL(q.dequeue(), 3);
    EXPECT_EQUAL(q.dequeue(), 4);
    EXPECT_EQUAL(q.dequeue(), 5);
    EXPECT_EQUAL(q.dequeue(), 6);
    EXPECT(q.isEmpty());
}
