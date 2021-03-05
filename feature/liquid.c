// liquid.c

#include <dbase.h>
#include <name.h>
#include <function.h>

void init()
{
	if(environment()==this_player())
	{
        	add_action("do_drink", "drink");
        	add_action("do_fill", "fill");
	}
}

string extra_long()
{
        int amount, max;
        string str;

        if( amount = query("liquid/remaining") ) {
                max = query("max_liquid");
                if( amount == max )
                        str = "里面装满了" + query("liquid/name") + "。\n";
                else if( amount > max/2 )
                        str = "里面装了七、八分满的" + query("liquid/name") + 
"。\n";
                else if( amount >= max/3 )
                        str = "里面装了五、六分满的" + query("liquid/name") + 
"。\n";
                else if( amount > max/4 )
                        str = "里面装了少许的" + query("liquid/name") + 
"。\n";
                return str;
        }
        else return 0;
}

int do_drink(string arg)
{
	int remain,avai;	
        mixed no_meal;
        if( !this_object()->id(arg) ) return 0;
        if( this_player()->is_busy() )
                return notify_fail("你上一个动作还没有完成。\n");
        if (no_meal = environment(this_player())->query("no_meal")){
        	if (stringp(no_meal))
        		return notify_fail(no_meal);
        	else
        		return notify_fail("此地禁止吃喝。\n");
        }
        if( !query("liquid/remaining") )
                return notify_fail( name() + (query("liquid/name") ? "已经被喝得一滴也不剩了。\n":"是空的。\n"));
        if( (int)this_player()->query("water") >= (int)this_player()->max_water_capacity() )
                return notify_fail("你已经喝太多了，再也灌不下一滴水了。\n");
	remain =(int) query("liquid/remaining") * 30;
	avai = (int)this_player()->max_water_capacity() - (int)this_player()->query("water");
	if( remain > avai )
	{
		this_player()->add("water", avai);	
		add("liquid/remaining", -(avai/30));
	}
	else
	{
		this_player()->add("water",remain);
		set("liquid/remaining", 0);
	}
        message_vision("$N拿起" + name() + "咕噜噜地喝了几口" + query("liquid/name")+ "。\n", this_player());

        if( this_player()->is_fighting() ) this_player()->start_busy(3);
	else this_player()->start_busy(1);

        
        if( !query("liquid/remaining") )
                write("你已经将" + name() + "里的" + query("liquid/name")
                        + "喝得一滴也不剩了。\n");

// This allows customization of drinking effect.
     	if (query("liquid/drink_func"))
           	return 1;
				
        switch(query("liquid/type")) {
                case "alcohol":
                        this_player()->apply_condition("drunk",
                                (int)this_player()->query_condition("drunk") 
                                + (int)query("liquid/drunk_apply"));
                        break;
        }
        
        return 1;
}


int do_fill(string arg)
{
    	string name, type, container;
    	int drunk_apply;
    	if( !this_object()->id(arg) ) return 0;
    	if( this_player()->is_busy() )
        	return notify_fail("你上一个动作还没有完成。\n");
    	if( !environment(this_player())->query("resource/water") )
        	return notify_fail("这里没有地方可以装水。\n");

    	if( query("liquid/remaining") )
        	message_vision("$N将" + name() + "里剩下的" + query("liquid/name") + "倒掉。\n", this_player());
    	type = environment(this_player())->query("liquid/type");
    	if(!stringp(type)) type="water";
    	name = environment(this_player())->query("liquid/name");
    	if(!stringp(name)) name="清水";
    	container=environment(this_player())->query("liquid/container");
    	drunk_apply = environment(this_player())->query("liquid/drunk_apply");
    	if(stringp(container))
        	message_vision("$N从"+container+"中将" + name() + "装满"+name+"。\n",this_player());
    	else 
    		message_vision("$N将" + name() + "装满"+name+"。\n", this_player());
    
    	if( this_player()->is_fighting() ) this_player()->start_busy(2);
    	set("liquid/type", type);
    	set("liquid/name", name);
    	set("liquid/remaining", query("max_liquid"));
    	if(drunk_apply) set("liquid/drunk_apply",drunk_apply);
    	set("liquid/drink_func", 0);
        return 1;
}
 

