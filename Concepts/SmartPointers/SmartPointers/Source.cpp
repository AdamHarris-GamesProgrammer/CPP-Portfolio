#include <iostream>
#include <string>
#include <memory>

//smart pointers can be used to automatically assign and remove memory to a pointer 
//smart pointers will call new and allocate memory as soon as they are created
//unique_ptr is a pointer that will automatically be deleted when it goes out of scope, such as the end of a method or a block of code
//a unique_ptr cannot be copied 
//shared_ptr is a pointer that can be copied and when it is copied it increments a reference counter when it goes out of scope this reference counter is decreased
//when the reference counter hits 0 the memory is expired and therefore deleted
//weak_ptr can be used to copy a shared_ptr but without incrementing its reference counter, this can be used to check the lifetime of a shared_ptr or perhaps to perform a small operation on the memory

class Entity {
public:
	Entity() {
		std::cout << "Created entity!" << std::endl;
	}

	~Entity() {
		std::cout << "Destroyed entity!" << std::endl;
	}

	void Print(std::string message) {
		std::cout << message << std::endl;
	}
};


int main() {

	//Creates a new scope to showcase unique_ptr being automatically deleted as it goes out of scope
	{
		//there are two ways to declare a unique_ptr

		//option A
		std::unique_ptr<Entity> entity1(new Entity());

		//option B
		//This is the preferred way as it is safer against exceptions
		std::unique_ptr<Entity> entity = std::make_unique<Entity>();

		//This below line causes a error as the copy operator '=' cannot be used on a unique_ptr as it has been overridden in the unique_ptr class to equal delete 
		//std::unique_ptr<Entity> e0 = entity;

		//You can access a objects methods the same way as a regular pointer.
		entity->Print("unique_ptr message");
	}
	//entity1 and entity pointers are deleted here as they are no longer in scope.


	
	//shared_ptr uses reference counting to stop memory being automatically deleted when a pointer goes out of scope.
	//for example if i have two shared_ptrs equal to the same object then they wont delete the memory until both the pointers are out of scope
	{
		//created a empty shared_ptr
		std::shared_ptr<Entity> e0;
		{
			//sharedEntity is created and filled with a Entity object, the line below will call the constructor which will output "Created Entity!" 
			std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
			//set e0 to sharedEntity
			e0 = sharedEntity;
		}
		//sharedEntity goes out of scope however the destructor is not called as e0 is still alive
		e0->Print("Ah, Ah, Ah Staying alive!!!");
	}
	//e0 goes out of scope and with it the last reference to sharedEntity is destroyed so the memory will now be deallocated

	//the final type of smart pointer is a weak_ptr this is a way of copying a sharedEntity but without increasing the reference count. 
	std::weak_ptr<Entity> weakEntity;
	{
		std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
		//sharedEntity reference counter is still at 1 even after assigning weakEntity to it. 
		 weakEntity = sharedEntity;
		 
		 if (!weakEntity.expired()) {
			 std::cout << "weakEntity has not expired" << std::endl;
		 }
		 sharedEntity->Print("sharedEntity going out of scope");
	}
	//sharedEntity now has 0 references so it gets deleted 
	//this code checks if the memory that weakEntity is pointing to has expired or not. 
	if (weakEntity.expired()) {
		//as sharedEntiy reference counter is now 0 and it has been deleted the weakEntity has now expired.
		std::cout << "weakEntity has expired" << std::endl;
	}
	


	std::cin.get();

}