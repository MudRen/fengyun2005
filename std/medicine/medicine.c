#include <dbase.h>
#include <name.h>
#include <ansi.h>
inherit COMBINED_ITEM;

void create() {
	if(clonep(this_object())) {
		destruct(this_object());
		return notify_fail("CAN NOT CLONE STARNDARD OBJECT!\n");
	}
}


void init()
{
  	if(this_player()==environment())
		add_action("apply_medicine",({"use","yong"}));
}


string 	herb_desc()
{
	string desc, type, pos;
	
	switch (query("field"))
	{
		case "kee":	pos = "气血"; break;
		case "gin":	pos = "精力"; break;
		case "sen":	pos = "心神"; break;
		default:	pos = "";
	}
		
	switch (query("type"))
	{
		case "poison":	desc = "带毒的药草，";
				desc += "中毒者"+ pos + "损伤"+ query("effect")+"点，需"
					+query("level")+"级药道，中毒几率为"+ query("proc")+"%。\n";
				break;
		case "cure":	desc = "该药草可治愈"+query("effect")+ "点"+ pos+"外伤，需"
					+query("level")+"级药道。\n";
				if (sscanf(query("heal_type"),"%s/%d",type, amount)== 2 )
				{
					desc += "直接服用（use）可治愈"+(amount)+"点"+ pos+ "外伤。\n";	
				}
				break;
		case "full":	desc = "该药草可治愈"+query("effect")+ pos+"损伤，需"
					+query("level")+"级药道。\n";
				if (sscanf(query("heal_type"),"%s/%d",type, amount)== 2 )
				{
					desc += "直接服用（use）可治愈"+amount+"点"+ pos+ "外伤。\n";	
				}
				break;
		case "depoison":desc = "该药草可解去"+query("field")+"之毒性，需"
					+query("level")+"级药道。\n";
				break;
		default:  desc = "一种药草，不清楚有什么功效。\n";
	}
	if (query("extra_desc"))	desc = desc + query("extra_desc") + "\n";
	return desc;	
}


int apply_medicine(string arg)
{
	int amount;
	string type, verb, pos;
	int diff;
	
	if (arg == query("id") || arg == query("name")) {
//	if (arg!= query("id") && arg!= query("name"))
//		return notify_fail("你要使用哪一样物件？？\n");
		if (this_player()->is_fighting())
		    	return notify_fail("你正在战斗中，先解决敌人再说吧。\n");
		if (this_player()->is_busy() && !query("pro_busy"))
		   	return notify_fail("你现在正忙，等一会儿吧。\n"); 	
		if (query("type") != "cure" && query("type")!= "full")
			return notify_fail("这件物品如此使用没有治疗作用。\n");
	
		if (sscanf(query("heal_type"),"%s/%d",type, amount)!= 2 )
			return notify_fail("这件物品没有治疗作用。\n");
		
		diff = this_player()->query("max_"+type)-this_player()->query("eff_"+type);
		if(!(diff))    return notify_fail("你没有受伤！\n");
		
		amount = amount* (100 + this_player()->query_skill("prescription",1)/2)/100;
		if(amount > diff) amount = diff;
		this_player()->add("eff_"+type,amount);
		this_player()->status_msg(type);
		
		// This allows customization of eating effect.
		if( query("use_func")) {
			add_amount(-1);
			return 1;
		}
		
		switch (query("usage_type")) {
			case "pill":	verb = YEL"$N服下一粒"+name(); break;
			case "piece":	verb = YEL"$N敷上一张"+name(); break;
			case "herb":    verb = YEL"$N将"+name()+YEL"嚼烂敷在伤口上"; break;
			default :	verb = YEL"$N使用"+name();
		} 
			  
		message_vision(verb+"。\n"NOR,this_player());
		switch (type)
		{
			case "kee":	pos = "气血"; break;
			case "gin":	pos = "精力"; break;
			case "sen":	pos = "心神"; break;
			default:	pos = "";
		}
		tell_object(this_player(),"你的"+pos+"治愈了"+amount+"点。\n");
		this_player()->perform_busy(1);
		add_amount(-1);
		return 1;
	}
}



