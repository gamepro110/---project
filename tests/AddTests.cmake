cmake_minimum_required(VERSION 3.10)
include_guard(GLOBAL)

include(CTest)
include(Catch)

function(AddTests TestName sourceFile libLinkTargets)

	set(fullName "${PROJECT_NAME}_${TestName}")
	set(_runtime "${fullName}_Tests")

	add_executable(${_runtime} ${sourceFile})

	set_target_properties(
		${_runtime}
		PROPERTIES
		POSITION_INDEPENDENT_CODE ON
		FOLDER "Tests/"
	)

	target_include_directories(
		${_runtime}
		PUBLIC
		"${PROJECT_SOURCE_DIR}/tests/catch/"
		"${PROJECT_SOURCE_DIR}"
	)

	target_link_libraries(
		${_runtime}
		PUBLIC
		catch_main
		${libLinkTargets}
	)

	add_test("${_runtime}" "${_runtime}")

endfunction(AddTests TestName sourceFile libLinkTargets)
