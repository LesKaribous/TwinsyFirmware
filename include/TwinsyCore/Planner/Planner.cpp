
#include "TwinsyCore/Planner/Planner.h"

/* --- Planner --- */

std::vector<Block*> Planner::program;
bool Planner::running;
int  Planner::currentBlock;

void Planner::init(){
    currentBlock = 0;
    running = false;
}

void Planner::appendBlock(Block* block){
    program.push_back(block);
}

void Planner::removeBlock(int id){
    if(id < program.size() && id >= 0){
        delete program[id];
        program.erase(program.begin() + id);
    }
}

void Planner::flush(){
    while (program.size() > 0){
        removeBlock(0);
    }
    running = false;
}

void Planner::execAll(){
    while(running)
        exec();
    
}

void Planner::start(){
    running = true;
}

void Planner::stop(){
    running = false;
}

void Planner::exec(){
    if(running){
        State currentState = Planner::program[currentBlock]->getState();
        if(Planner::currentBlock < program.size()){
            if(currentState == FINISHED){
                currentBlock++;
                if(currentBlock >= program.size()){
                    flush();
                }
            }else
                program[currentBlock]->exec();
        }
    }
}

bool Planner::isRunning(){
    return running;
}
