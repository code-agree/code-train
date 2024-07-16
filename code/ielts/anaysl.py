# import pandas as pd
# import matplotlib.pyplot as plt

# # Creating the DataFrame from the provided data
# data = {
#     'date': ['202405', '202404', '202312'],
#     'listening': [5.5, 4.5, 4.5],
#     'reading': [6, 6, 7],
#     'writting': [5.5, 5, 5],
#     'speaking': [4, 4.5, 5],
#     'total': [5.5, 5, 5.5]
# }

# df = pd.DataFrame(data)

# # Plotting the data
# plt.figure(figsize=(12, 6))

# # Plot each score category
# for column in df.columns[1:]:
#     plt.plot(df['date'], df[column], marker='o', label=column)

# # Adding titles and labels
# plt.title('analasys')
# plt.xlabel('date')
# plt.ylabel('score')
# plt.ylim(0, 10)
# plt.legend()

# # Display the plot
# plt.grid(True)
# plt.show()

import pandas as pd
import matplotlib.pyplot as plt

# Creating the DataFrame from the provided data
data = {
    'date': ['202312', '202404', '202405'],
    'listening': [4.5, 4.5, 5.5],
    'reading': [7, 6, 6],
    'writting': [5, 5, 5.5],
    'speaking': [5, 4.5, 4],
    'total': [5.5, 5, 5.5]
}

df = pd.DataFrame(data)

# Define different markers for each data series
markers = ['o', 's', '^', 'D', 'x']

# Plotting the data
plt.figure(figsize=(12, 6))

# Plot each score category with different markers
for i, column in enumerate(df.columns[1:]):
    plt.plot(df['date'], df[column], marker=markers[i], label=column)

# Adding titles and labels
plt.title('IELTS Scores Analysis')
plt.xlabel('Date')
plt.ylabel('Score')
plt.ylim(4, 8)
plt.legend()

# Display the plot
plt.grid(True)
plt.show()
