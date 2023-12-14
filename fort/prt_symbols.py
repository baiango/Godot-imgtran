import subprocess
import os

# Define the directory containing the .obj files
directory_path = '.'

# List all .obj files in the directory
obj_files = [f for f in os.listdir(directory_path) if f.endswith('.obj')]

# Create a text file to save the results
output_file = 'nm_results.txt'

# Open the output file for writing
with open(output_file, 'w') as f:
	f.write(f"This file is for printing function names in Fortran compiled source files.")
	f.write('\n\n')

	for obj_file in obj_files:
		# Build the nm command and run it
		obj_file_path = os.path.join(directory_path, obj_file)
		command = f'nm "{obj_file_path}"'
		result = subprocess.run(command, shell=True, capture_output=True, text=True)

		# Check for errors
		if result.returncode == 0:
			# Split the nm output into lines
			lines = result.stdout.splitlines()

			# Filter lines with "0000000000000000 T" prefix
			filtered_lines = [line for line in lines if line.startswith("0000000000000000 T")]

			# Write the filtered lines to the output file
			f.write(f"Results for {obj_file}:\n")
			f.write('\n'.join(filtered_lines))
			f.write('\n\n')
		else:
			f.write(f"Error running nm for {obj_file}:\n")
			f.write(result.stderr)

print(f"Results saved to {output_file}")
