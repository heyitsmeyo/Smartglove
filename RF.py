# -*- coding: utf-8 -*-
"""Untitled4.ipynb

Automatically generated by Colab.

Original file is located at
    https://colab.research.google.com/drive/1rVMw5F4jwH6K9O_yiGH7QNco9r_Ueuaw
"""

from sklearn.tree import plot_tree
from joblib import dump, load
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.metrics import confusion_matrix
from sklearn.preprocessing import LabelEncoder
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.ensemble import RandomForestClassifier
import pandas as pd
import os
import numpy as np
from sklearn.metrics import confusion_matrix, ConfusionMatrixDisplay
from sklearn.metrics import accuracy_score
import matplotlib.pyplot as plt
from sklearn.metrics import mean_squared_error
from sklearn.model_selection import cross_val_score
from sklearn.metrics import classification_report



#alphabets = [ 'a', 'b', 'c', 'd','e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']



#alphabets = [ 'f',  'h', 'i', 'j',  'l', 'n',  'p', 'w', 'x', 'y', 'z', 'hungry', 'hello', 'thankyou', 'goodbye', 'sorry']
#alphabets = ['bad','deaf','fine','good','goodbye','hello','hungry','me','no','please','sorry','thankyou','yes','you' ]
alphabets = [ 'a', 'b', 'c', 'd','e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'bad','deaf','fine','good','goodbye','hello','hungry','me','no','please' ]


merged_dfs = []

for alphabet in alphabets:
    file_path = f'/content/drive/MyDrive/alphabet/{alphabet}_merged.csv_exported.csv'
    if os.path.exists(file_path):
        df = pd.read_csv(file_path)
        if not df.empty:
            merged_dfs.append(df)

combined_df = pd.concat(merged_dfs, ignore_index=True)
columns_to_filter = ['flex_1', 'flex_2', 'flex_3', 'flex_4', 'flex_5']
combined_df[columns_to_filter] = combined_df[columns_to_filter].where(combined_df[columns_to_filter] >= 0, 0)
combined_df.dropna(subset=columns_to_filter, inplace=True)


#combined_df.reset_index(drop=True, inplace=True)
X = combined_df.drop(['Alphabet', 'timestamp', 'user_id',
                      'Qw', 'Qx', 'Qy', 'Qz', 'ACCx_body',
                      'ACCy_body',
                      'ACCz_body',
                      'ACCx_world', 'ACCy_world', 'ACCz_world'], axis=1)
y = combined_df['Alphabet']

le = LabelEncoder()
y_encoded = le.fit_transform(y)
scaler = StandardScaler()
X_scaled = scaler.fit_transform(X)


X_train, X_test, y_train, y_test = train_test_split(X_scaled, y_encoded, test_size=0.3, random_state=10)


#model = RandomForestClassifier(n_estimators=600, random_state=15 , oob_score = True )
model = RandomForestClassifier(n_estimators= 2000, random_state=15 , oob_score = True , min_samples_leaf=5 ,   max_samples = 50 , max_depth = 5 , min_samples_split=4 , max_leaf_nodes = 150 )

#model = RandomForestClassifier(n_estimators=600, random_state=15 , oob_score = True ,  min_samples_leaf=5 ,   max_samples = 400 , max_depth = 6 , min_samples_split=6 , max_leaf_nodes = 150)
model.fit(X_train, y_train)
y_pred = model.predict(X_test)



accuracy = accuracy_score(y_test, y_pred)
print(f"Accuracy: {accuracy}")


oob_score = 1 -  model.oob_score_
print(f"Out-of-Bag Score: {oob_score}")

mse = mean_squared_error(y_test, y_pred)
print(f"Mean Squared Error: {mse}")



y_true = y_test
#y_pred = model.predict(X_test)



confusion_matrix = confusion_matrix(y_true, y_pred)

class_labels = alphabets
confusion_matrix_norm = confusion_matrix / confusion_matrix.sum(axis=1)[:, np.newaxis]
plt.figure(figsize=(20, 20))

# Choose a colormap
cmap = sns.color_palette("Blues", as_cmap=True)

# Generate the heatmap
sns.heatmap(confusion_matrix_norm, annot=True, cmap=cmap, fmt=".2f", xticklabels=class_labels, yticklabels=class_labels)

# Add labels and title
plt.xlabel("Predicted Label", fontsize=12)
plt.ylabel("True Label", fontsize=12)
plt.title("Confusion Matrix", fontsize=14)
plt.show()



# Assuming 'y_true' contains the true labels and 'y_pred' contains the predicted labels
#report = classification_report(y_true, y_pred, output_dict=True)
#report_df = pd.DataFrame(report).transpose()

# Save the DataFrame to a CSV file
#report_df.to_csv('classification_alphabet85.csv', index=True)



# Save the trained model

    # Calculate confusion matrix