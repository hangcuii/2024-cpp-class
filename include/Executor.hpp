//
// Created by cuihang on 2024/12/3.
//

#ifndef CPP_TRAINING_EXECUTOR_HPP
#define CPP_TRAINING_EXECUTOR_HPP

#endif  // CPP_TRAINING_EXECUTOR_HPP
#pragma once
#include <string>
namespace adas
{

enum class Heading {
    North,
    East,
    South,
    West
};


struct Pose
{   int x;
    int y;
    Heading heading;


};


class Executor
{
public:
    static Executor* NewExecutor(const Pose& pose ={0,0,Heading::North}) noexcept;

public:
    Executor(void) = default;
    virtual ~Executor(void) = default;
    Executor(const Executor&) = delete;
    Executor& operator=(const Executor&) = delete;
public:
    virtual void Execute(const std::string& command) noexcept = 0;
    virtual Pose Query(void) const noexcept = 0;
};
}