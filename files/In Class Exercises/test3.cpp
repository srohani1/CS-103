#include <vector>
struct Item
{
	double weight;
	double value;
	int id;
}
class Knapsack 
{
	public:
	Knapsack(double weight);
	~Knapsack();
	std::Vector<Item> getCurrentItems();
	void addItem(Item in);
	void removeItem();
	double getWeight();
	double getValue();
	double getMaxWeight();
private:
	double max_weight;
	double current_weight;
	double current_value;
	std::vector<Items>item;
}

Knapsack::Knaspsack (double weight)
{
	max_weight = weight;
}
