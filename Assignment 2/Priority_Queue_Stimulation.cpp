#include <iostream>
using namespace std;

class PatientNode
{
public:
  string name;
  int arrivalNumber;
  string condition;
  int priority;
  PatientNode *next;

  PatientNode(string name, int arrivalNumber, string condition, int priority)
  {
    this->name = name;
    this->arrivalNumber = arrivalNumber;
    this->condition = condition;
    this->priority = priority;
    next = NULL;
  }
};

class PatientQueue
{
public:
  PatientNode *head;
  PatientNode *tail;

  PatientQueue()
  {
    head = tail = NULL;
  }

  void addPatient(string name, int arrivalNumber, string condition, int priority)
  {
    PatientNode *newNode = new PatientNode(name, arrivalNumber, condition, priority);

    if (head == NULL)
    {
      head = tail = newNode;
      return;
    }

    if (priority < head->priority)
    {
      newNode->next = head;
      head = newNode;
      return;
    }

    PatientNode *curr = head;
    PatientNode *prev = NULL;

    while (curr != NULL && curr->priority <= priority)
    {
      prev = curr;
      curr = curr->next;
    }

    prev->next = newNode;
    newNode->next = curr;

    if (curr == NULL)
    {
      tail = newNode;
    }
  }

  void displayQueue()
  {
    cout << "\n=================== Current Patient Queue =====================\n";
    PatientNode *curr = head;
    if (curr == NULL)
    {
      cout << "No patients currently in the queue.\n";
      return;
    }
    while (curr != NULL)
    {
      cout << "Name: " << curr->name << " | Arrival #: " << curr->arrivalNumber
           << " | Condition: " << curr->condition << " | Priority: " << curr->priority << endl;
      curr = curr->next;
    }
  }
};

int main()
{
  PatientQueue queue;
  int exitFlag = 0;

  while (!exitFlag)
  {
    cout << "\n==================== Medical Scheduler ====================\n";
    cout << "1) Add New Patient\n";
    cout << "2) View Patient Queue\n";
    cout << "3) Exit\n";
    cout << "------------------------------------------------------------\n";

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
      cout << "\n==================== Add Patient ====================\n";
      string name, condition;
      int arrivalNumber, priority;

      cout << "Enter Patient Name: ";
      cin >> name;

      cout << "Enter Arrival Order Number: ";
      cin >> arrivalNumber;

      cout << "Enter Emergency Condition: ";
      cin.ignore();
      getline(cin, condition);

      if (condition == "Heart Attack" || condition == "Stroke")
        priority = 1;
      else if (condition == "Broken Leg" || condition == "Severe Burn" || condition == "Fractured Arm")
        priority = 2;
      else if (condition == "Fever" || condition == "Food Poisoning" || condition == "Migraine")
        priority = 3;
      else if (condition == "Mild Cold" || condition == "Small Cut")
        priority = 4;
      else
      {
        cout << "Invalid emergency condition entered.\n";
        continue;
      }

      queue.addPatient(name, arrivalNumber, condition, priority);
      cout << "Patient added successfully!\n";
    }
    else if (choice == 2)
    {
      queue.displayQueue();
    }
    else if (choice == 3)
    {
      exitFlag = 1;
      cout << "Exiting the system...\n";
    }
    else
    {
      cout << "Invalid input. Please try again.\n";
    }
  }

  return 0;
}
