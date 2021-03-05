// food.c

#include <dbase.h>
#include <name.h>

void init()
{
	if(environment()==this_player())
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	int avai,remain, cost;
	mixed no_meal;
	
	if( !this_object()->id(arg) ) return 0;
	if( this_player()->is_busy() )
		return notify_fail("你上一个动作还没有完成。\n");
	if ( no_meal = environment(this_player())->query("no_meal"))
	{
		if (stringp(no_meal))
			return notify_fail(no_meal);
		else 
			return notify_fail("此地禁止吃喝。\n");
	}
	if( !query("food_remaining") )
		return notify_fail( name() + "已经没什麽好吃的了。\n");
	if( (int)this_player()->query("food") >= (int)this_player()->max_food_capacity() )
		return notify_fail("你已经吃太饱了，再也塞不下任何东西了。\n");
	remain = (int) query("food_remaining") * (int) query("food_supply");
	avai = (int)this_player()->max_food_capacity() - (int)this_player()->query("food");
        if( remain > avai )
        {
        	this_player()->add("food", avai);
        	cost = (avai/query("food_supply")>0)? avai/query("food_supply"):1;
        	add("food_remaining", -cost);
        }
        else
        {
        	this_player()->add("food",remain);
        	set("food_remaining", 0);
        }

	if( this_player()->is_fighting() )
		this_player()->start_busy(3);
	else
		this_player()->start_busy(1);

	// This allows customization of drinking effect.
	if(query("eat_func")) return 1;

	set("value", 0);
	if( !query("food_remaining") ) {
		if (!query("finish_msg"))
			message_vision("$N将手中的" + name() + "吃得干干净净。\n", this_player());
		else
			message_vision(query("finish_msg"), this_player());				
		if( !this_object()->finish_eat() )
			destruct(this_object());
	} else 
		message_vision("$N拿起" + name() + "咬了几口。\n", this_player());

	return 1;
}

