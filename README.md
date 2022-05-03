# wifi360_evb_pico

## 개발환경 
기본 개발환경 구축은 아래 링크를 참조한다.
- https://blog.naver.com/chcbaram/222561278866


## CMake Configure (Windows)
```
cmake -S . -B build -G "MinGW Makefiles" -DPICO_BOARD=pico
```

## CMake Configure (Linux)
```
cmake -S . -B build -G "Unix Makefiles" -DPICO_BOARD=pico
```

## CMake Build
```
cmake --build build -j4
```

## Optional
### [Task Runner Extention](https://marketplace.visualstudio.com/items?itemName=SanaAjani.taskrunnercode)
- VS Code extension to view and run tasks from Explorer pane
- 아래와 같이 Build와 Download를 위한 run task를 등록하여 쉽게 사용 가능
	```
	// For tasks.json
	{
		// See https://go.microsoft.com/fwlink/?LinkId=733558
		// for the documentation about the tasks.json format
		"version": "2.0.0",
		"tasks": [
			{
				"label": "cmake_build",
				"type": "shell",
				"command": "cmake --build build -j4",
				"problemMatcher": [],
				"group": {
					"kind": "build",
					"isDefault": true
				}
			},
			{
				"label": "uf2_down",
				"type": "shell",
				"command": "python ./tools/down.py COM50",
			}
		]
	} 
	```