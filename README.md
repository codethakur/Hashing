## 📌 Hashing
Hashing is a technique used to store and retrieve data efficiently using a hash function that maps keys to unique indices in a hash table. It is widely used in data structures like `unordered_map`, `unordered_set`, and custom hash tables.

---

## 🔹 Components of Hashing in C++

### 1️⃣ Hash Function
A mathematical function that takes an input (key) and converts it into a hash code (index).  
The goal is to distribute values evenly to reduce collisions.

### 2️⃣ Hash Table
A fixed-size array where hashed values are stored.  
The index in the hash table is determined by the hash function.

### 3️⃣ Collision Handling
When two keys map to the same index, we need a way to store both:

#### 📍 (a) Chaining (Separate Chaining)
Each index stores a linked list of values.

