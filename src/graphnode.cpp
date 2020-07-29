#include "graphedge.h"
#include "graphnode.h"

#include <iostream>
#include <memory>

GraphNode::GraphNode(int id) : _chatBot(nullptr)
{
    _id = id;
}

GraphNode::~GraphNode()
{
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    _childEdges.emplace_back(std::move(edge));
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
    //std::cout << "Entering MoveChatbotHere" << std::endl;
    //std::cout << "MoveChatbotHere Step 1" << std::endl;
    _chatBot.reset(new ChatBot());
    //std::cout << "MoveChatbotHere Step 2" << std::endl;
    *_chatBot = std::move(chatbot);
    //std::cout << "MoveChatbotHere Step 2" << std::endl;
    _chatBot->SetCurrentNode(this);
    //std::cout << "Exiting MoveChatbotHere" << std::endl;
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(std::move(*_chatBot));
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}