"""
Manage students and disciplines.
The user can add, remove, update, and list both students and disciplines.
Grade students at a given discipline. Any student may receive one or several grades at any discipline. Deleting a student also removes their grades. Deleting a discipline deletes all grades at that discipline for all students.
Search for disciplines/students based on ID or name/title. The search must work using case-insensitive, partial string matching, and must return all matching disciplines/students.
Create statistics:
All students failing at one or more disciplines (students having an average <5 for a discipline are failing it)
Students with the best school situation, sorted in descending order of their aggregated average (the average between their average grades per discipline)
All disciplines at which there is at least one grade, sorted in descending order of the average grade(s) received by all students
"""

from src.ui.ui import UserInterface
from src.services.services import Services, get_repository

if __name__ == '__main__':
    try:
        student_repo, discipline_repo, grade_repo = get_repository()
        services = Services(student_repo, discipline_repo, grade_repo)
        ui = UserInterface(services)
        ui.run()
    except ValueError as ve:
        print(ve)
