import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

# Read the Titanic dataset CSV file
titanic_data = pd.read_csv('titanic.csv')


# Define a function to categorize passengers as men, women, or children
def categorize_passenger(row):
    if row['who'] == 'man':
        return 'Men'
    elif row['who'] == 'woman':
        return 'Women'
    else:
        return 'Children'


# Apply the categorize_passenger function to create a new 'passenger_type' column
titanic_data['passenger_type'] = titanic_data.apply(categorize_passenger, axis=1)

# Calculate survival rate for each combination of passenger type and class
survival_rate_data = titanic_data.groupby(['class', 'passenger_type'])['survived'].mean().reset_index()

# Create a bar plot to visualize the survival rate of men, women, and children in each class
plt.figure(figsize=(10, 6))
sns.set(style="whitegrid")
sns.barplot(data=survival_rate_data, x='class', y='survived', hue='passenger_type',
            hue_order=['Men', 'Women', 'Children'])
plt.title("Survival Rate of Men, Women, and Children in Each Class")
plt.xlabel("Class")
plt.ylabel("Survival Rate")
plt.legend(title="Passenger Type")
plt.tight_layout()

# Display the plot
plt.show()

