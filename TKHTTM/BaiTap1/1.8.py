import matplotlib.pyplot as plt
import numpy as np

# Sample student data
student_data = [
    {'student_name': 'Phuc', 'Math': 85, 'Science': 78, 'History': 92, 'English': 88, 'Art': 70},
    {'student_name': 'Dung', 'Math': 78, 'Science': 80, 'History': 85, 'English': 92, 'Art': 68},
    {'student_name': 'Khiem', 'Math': 92, 'Science': 75, 'History': 80, 'English': 70, 'Art': 90}
]

# Extract subjects and marks
subjects = ['Math', 'Science', 'History', 'English', 'Art']
marks = np.array([[student[subject] for subject in subjects] for student in student_data])
student_names = [student['student_name'] for student in student_data]

# Plotting Multiple Lines in the Same Chart
plt.figure(figsize=(10, 6))
for i in range(len(student_data)):
    plt.plot(subjects, marks[i, :], marker='o', label=student_names[i])

plt.xlabel('Subjects')
plt.ylabel('Marks')
plt.title('Plotting Multiple Lines in the Same Chart')
plt.grid(True)
plt.tight_layout()

# Show the plot
plt.show()

# Adding a legend
plt.figure(figsize=(10, 6))
for i in range(len(student_data)):
    plt.plot(subjects, marks[i, :], marker='o', label=student_names[i])

plt.xlabel('Subjects')
plt.ylabel('Marks')
plt.title('Adding a legend')
plt.grid(True)
plt.tight_layout()
plt.legend()

# Show the plot after adding a legend
plt.show()

# Plotting Bar Charts
plt.figure(figsize=(10, 6))
x = np.arange(len(subjects))  # x-coordinates for bars
width = 0.2  # width of the bars

for i in range(len(student_data)):
    plt.bar(x + i * width, marks[i, :], width=width, label=student_names[i])

plt.xlabel('Subjects')
plt.ylabel('Marks')
plt.title('Plotting Bar Charts')
plt.xticks(x + (len(student_data) - 1) * width / 2, subjects)  # Place x-ticks in the center of groups
plt.legend()
plt.grid(True)
plt.tight_layout()

# Show the plot
plt.show()
