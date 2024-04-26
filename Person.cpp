#include "Person.h"

Person::Person(): m_name(nullptr), m_id(0) {}
Person::Person( const char* name, int id ): m_name(nullptr), m_id(id) {
    SetName(name);
}
Person::Person( const Person& other ): m_name(nullptr), m_id(other.m_id) {
    SetName(other.m_name);
}
Person::~Person() { delete[] m_name; }

void Person::SetName( const char* newName ) {
    delete[] m_name; // Free existing memory
    m_name = new char[strlen(newName) + 1]; // Allocate new memory
    strcpy(m_name, newName); // Copy the new name
}
void Person::SetId( int newId ) { m_id = newId; }
char* Person::GetName() const { return m_name; }
int	Person::GetId() const { return m_id; }
