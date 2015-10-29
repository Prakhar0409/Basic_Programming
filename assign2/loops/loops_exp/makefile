# Default case (user-side)
PROJ_HOME ?= $(CURDIR)
TESTS_DIR ?= $(PROJ_HOME)/tests

# Project specific
NAME := loops_exp
SOURCES_LIST := loops_exp.cpp
MAKE_FILE := $(CURDIR)/$(lastword $(MAKEFILE_LIST))

# targets
all: build

build: $(SOURCES_LIST)
	g++ -o $(NAME) $(SOURCES_LIST)
	
run: build
	@echo "Running the program\nInput: "
	@$(PROJ_HOME)/$(NAME)

clean:
	rm -f $(NAME) run.log

check:
	@echo 'checking required files for submission'
	@if [ -e $(SOURCES_LIST) ]; then \
		echo "All files in place"; \
		echo "Run 'make submit.practice' to get the ZIP file to upload for a practice run."; \
		echo "Run 'make submit.grade' to get the ZIP file to upload for final submission."; \
	else \
		echo "Some required files missing" \
		echo "If you have accidently deleted files, restore them before running check again" \
		exit 1; \
	fi
	
tests: clean build
	@echo 'Running local test-suite'
	@$(CURDIR)/verifier --proj-dir=$(PROJ_HOME) --proj-name=$(NAME) --tests-dir=$(TESTS_DIR) --test-suite=local --make=$(MAKE_FILE)
	@cat run.log
	@echo 'Finished running all test cases'
	
submit: clean check
	@echo 'Generating ZIP file to upload'
	@cp -r ../$(NAME) /tmp/
	@rm -rf /tmp/$(NAME)/tests /tmp/$(NAME)/makefile /tmp/$(NAME)/verifier /tmp/$(NAME)/$(NAME).zip /tmp/$(NAME)/.cproject
	@cd /tmp; zip -r $(NAME).zip $(NAME); cd $(PROJ_HOME)
	@rm -rf /tmp/$(NAME)
	@mv -f /tmp/$(NAME).zip .
	
submit.practice: submit
	@echo 'Upload $(NAME).zip to https://10.237.20.228:1345/OnlineEvaluation/default/submit for a practice run'
	
submit.grade: submit
	@echo 'Upload $(NAME).zip to https://10.237.20.241:1345/OnlineEvaluation/default/submit to complete submission'

