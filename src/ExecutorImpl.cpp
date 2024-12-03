//
// Created by cuihang on 2024/12/3.
//
#include "ExecutorImpl.hpp"
namespace adas
{
Executor* Executor::NewExecutor(const Pose& pose) noexcept
{
    return new (std::nothrow) ExecutorImpl(pose);
}

ExecutorImpl::ExecutorImpl(const Pose& pose) noexcept:pose(pose)
{}

void ExecutorImpl::Execute(const std::string& command) noexcept
{
    for (const auto cmd : command)
    {
        if(cmd == 'M')
        {
            switch (pose.heading)
            {
            case Heading::East:
                ++pose.x;
                break;
            case Heading::West:
                --pose.x;
                break;
            case Heading::North:
                ++pose.y;
                break;
            case Heading::South:
                --pose.y;
                break;
            }
        }
        else if(cmd == 'L')
            pose.heading = static_cast<Heading>((static_cast<int>(pose.heading) + 3) % 4);
        else if(cmd == 'R')
            pose.heading = static_cast<Heading>((static_cast<int>(pose.heading) + 1) % 4);

    }



}

Pose ExecutorImpl::Query(void) const noexcept
{
    return pose;
}
}