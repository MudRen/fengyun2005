/*  Modified by Silencer 3/07/2003
	1.added numerous notify_fail messages, 
	2.do_drop or fly will always clear conditoin,
	3. No more unnecessary hawk-trainer kill,
*/

#include <ansi.h>
#include <globals.h>
inherit NPC;
string player_env(object target, object me);

//void eatMeat(object ob);
void create()
{
    	set_name(HIC"苍鹰"NOR, ({ "big hawk","hawk" }) );
    	set("race", "飞禽");
    	set("age", 1);
    	set("gender", "雄性");
    	set("long","
一只勾嘴利爪的苍鹰。它一双凶猛锐利的眼睛正盯着你看，毫无半分退缩
之意，有胆子你就去抓它吧(catch)，或者你也可以试着喂食它(feed)。\n");
    	set("attitude","peaceful");
    
		set("weight", 3000);
		set("agi", 40);
		set("per",30);
		set("str",100);

		set("resistance/kee",100);
		set("resistance/gin",100);
		set("resistance/sen",100);
		
		set_skill("move",800);
    	set_skill("unarmed",800);
    	set_skill("dodge",800);
    	
    	set("combat_exp", 7000000);
  
		set("marks/chained",1);
		set("marks/trained",0);
		set("no_give", 1);
		setup();
}


void init() 
{
	::init();
	add_action("do_catch", "catch");
	add_action("do_feed","feed");
	add_action("do_chain",({"chain","tie"}));
	add_action("do_drop","drop");
}


int checkChained()
{
	
	object hawk;
	hawk = this_object();
	if (hawk->query("marks/chained"))
	{
		object room;
		room = find_object("/d/huashan/fupi");
		if(environment() == room && room->query("item_desc") == 0)
		{
			room->set("item_desc", ([
			"chain": "一条系鹰用的细细的黑色铁链，似乎竟是玄铁做的。\n 你在想，不知道开铁链的钥匙在哪里。也许可用什么试试砍断(chop)它。 \n",
			"铁链":"一条系鹰用的细细的黑色铁链，似乎竟是玄铁做的。 \n 你在想，不知道开铁链的钥匙在哪里。也许可用什么试试砍断(chop)它。\n",
			]) );
		}
		//return notify_fail("苍鹰的脚上还系着铁链呢！ \n");
		return 1;
	}
	return 0;
}


int do_catch(string arg) 
{
	object me, hawk/*, chain*/, *inv;
	object hawktrainer;
	int i;
	me = this_player();
	hawk=this_object();
	if(!arg) 
	{
		return notify_fail("你想抓什么？\n");
	}
	
	if (me->is_busy())
		return notify_fail("你现在正忙。\n");
		
	if(arg != "hawk" && arg != "苍鹰" && arg!= "big hawk") 
	{
		return notify_fail("这个东西你抓不住。\n");
	}
	
	if(!present(hawk, environment(me)))
	{
        	return notify_fail("这儿没有苍鹰。\n");
    	}
	
	if( hawk->query("marks/trained"))
	{
        	return notify_fail("苍鹰已经对你俯首贴耳了。\n");
    	}
    	
	
	if (hawktrainer=present("trainer",environment(hawk)))
	{
		message_vision(RED"$N对$n大吼一声：想打我猎鹰的主意！你活得不耐烦了！ \n"NOR,
                       hawktrainer,this_player());
        	hawktrainer->ccommand("kick "+me->get_id());
        	me->perform_busy(1);
        	return 1;
	}
	if (checkChained())
	{
		return notify_fail("苍鹰的脚上还系着铁链呢！ \n");
	}
	
	if (random(4))
	{
		message_vision(HIW"苍鹰一声厉叫，警告$N不要靠近。\n"NOR,me);
	}
	else
	{
		message_vision(HIR"苍鹰一鼓翅膀，腾身而起，一双利爪抓向$N面前！\n"NOR,me);
		inv = all_inventory(me);
		for (i=0;i<sizeof(inv);i++ )
		{
			//write (inv[i]->name()+":"+inv[i]->query("equipped")+"\n");
			if (objectp(inv[i]) && (inv[i]->name()==YEL"眼罩"NOR) && (inv[i]->query("equipped")=="worn"))
			{
				message_vision(HIW"苍鹰的双爪啪地击在$N的眼罩上，好险啊。。。 \n"NOR,me);
				return 1;
			}
		}		
		tell_object(me, HIR"你双眼一阵剧痛！ \n 你的眼前一片漆黑。。。 \n"NOR);
//		me->add_temp("block_msg/all", 1);	-- too many loopholes.
	}
	me->perform_busy(1);
	return 1;
}


void eatMeat(object me)
{
	int avai,remain;
	object hawk,wolfmeat;
	hawk = this_object();
	call_out("eatMeat",20,me);
	if (!present(hawk,me))
	{
		remove_call_out("eatMeat");
		me->change_condition_duration("hawk_claw",0);
		message_vision("$N长啸一声，向长空飞去。\n",hawk);
		destruct(hawk);
	}
	if (wolfmeat = present("wolfmeat",me))
	{
		remain = (int)wolfmeat->query("food_remaining") * (int)wolfmeat->query("food_supply");
		avai = 100;
		//avai = (int)hawk->max_food_capacity() - (int)hawk->query("food");
		//make avai a certain amount to make hawk eat faster
		if( remain > avai )
		{
			add("food_remaining", -(avai/(int)wolfmeat->query("food_supply")));
		}
		else
		{
			//hawk->add("food",remain);
			wolfmeat->set("food_remaining", 0);
		}
			wolfmeat->set("value", 0);
			if( !wolfmeat->query("food_remaining") ) 
			{
				//meat is gone
				message_vision("$N将剩下的" + name() + "吃得乾乾净净。\n", hawk);
				if( !wolfmeat->finish_eat() )
					destruct(wolfmeat);
				message_vision("$N吃完$n手中的肉，腾身向空中飞去。\n",hawk,me);
				me->change_condition_duration("hawk_claw",0);
				remove_call_out("eatMeat");
				destruct(hawk);
			}
			else 
				message_vision("$N叼起$n咬了几口。\n", hawk,wolfmeat);
	}
	else
	{
		//dunno why have to do this
		message_vision("$n手中的肉被吃完了，$N腾身向空中飞去。\n",hawk,me);
		me->change_condition_duration("hawk_claw",0);
		remove_call_out("eatMeat");
		destruct(hawk);
	}
	return ;
}


int do_drop(string arg)
{
	object me,hawk;
	hawk = this_object();
	me = this_player();
	
	if (arg != "hawk" && arg !="苍鹰")
	{
		return 0;
	}
	//seems no need to check so many status, just for caution
	if(!present(hawk, me) || hawk->query("marks/owner"))
	{
		return 0;
	}
	me->change_condition_duration("hawk_claw",0);
	remove_call_out("eatMeat");
	if (hawk->query("marks/feeding"))
	{
		message_vision("$N手臂吃痛，不禁将苍鹰放了下来。\n",me);
	}
	message_vision("苍鹰在空中盘旋几圈，腾身飞去。\n",me);
	destruct(hawk);
	return 1;
}
     
int do_feed(string arg)
{
	object me;
	object wolfmeat,leathersleeves,hawktrainer;
	object hawk;
	string argmeat, arghawk;
	hawk = this_object();
	me = this_player();
	if(!(present(hawk, environment(me))) || hawk->query("marks/trained"))
	{
        	return 0;
    	}
	if(!arg) 
	{
		return notify_fail("你要喂谁什麽东西？(feed 某物 to 某人)\n");
    	}
    	if(sscanf(arg, "%s to %s", argmeat, arghawk)==2 || sscanf(arg, "%s %s", arghawk, argmeat)==2 );
    	else 
	{
		return notify_fail("你要喂谁什麽东西？(feed 某物 to 某人)\n");
    	}
    
	if (arghawk != "hawk" && arghawk != "苍鹰" && arghawk != "big hawk")
	{
		return notify_fail("你不能喂"+arghawk+"。\n");
	}
	
	if (argmeat =="wolf meat" && arg ==YEL"狼肉脯"NOR)
	{
		return notify_fail("苍鹰对你手里的"+argmeat+"似乎没什么兴趣，换点生猛的东西吧。\n");
	}
	
	if (argmeat !="wolfmeat" && arg !="狼肉脯")
	{
		return notify_fail("苍鹰对你手里的"+argmeat+"似乎没什么兴趣，换点生猛的东西吧。\n");
	}
	
	if (!wolfmeat=present("wolfmeat",me))
	{	
		return notify_fail("你身上没有狼肉脯。\n");
	}
	
	if (!wolfmeat->query("hawk_food"))
	{
		return notify_fail("苍鹰对这块狼肉脯看了看，似乎没什么兴趣，也许它只对生的感兴趣。\n");
	}
	
	if (checkChained())
	{
		return notify_fail("苍鹰的脚上还系着铁链呢，不能飞过来吃肉！\n");
	}
	
	if (hawktrainer = present("hawk trainer",this_object()))
	{

        	message_vision(RED"$N对$n大吼一声：想打我猎鹰的主意！你活得不耐烦了！ \n"NOR,
                       hawktrainer,me);
        	hawktrainer->ccommand("kick "+me->get_id());
        	me->perform_busy(1);
        	return 1;
    	}
	
	message_vision("$N试着拿出狼肉脯逗引苍鹰。\n ",me);
	if (random(10) && me->query("kar")<=20)
	{
		message_vision("苍鹰犹疑不定地看着$N。\n" ,me);
		return 1;
	}
	if (hawk->move(me))
	{
		message_vision("苍鹰飞上$N的手臂，从$N手里叼过狼肉脯吃了起来。\n",me);
		if (!leathersleeves=present("leather sleeves",me))
		{
			me->apply_condition("hawk_claw",10);
		}
		hawk->set("marks/feeding",1);
		call_out("eatMeat",10,me);
	}
	else
	{
		tell_object(me,"你现在无法承受苍鹰的重量。\n");
	}
	return 1;
}

int do_chain(string arg)
{
	object hawk, me,chain, new_hawk;
	hawk = this_object();
	me = this_player();
	
	
	if (arg != "hawk" && arg !="苍鹰" && arg!= "big hawk")
	{
		return notify_fail("你没法拴住这个东西。\n");
	}
	
	if (!chain = present("chain",me))
	{
		return notify_fail("你手里没有链条啊。\n");
	}
	
	if (!present(hawk, me))
		return notify_fail("苍鹰不在你身上。\n");
		
	if (!hawk->query("marks/feeding"))
		return notify_fail("苍鹰警惕地看着你，你赶忙缩回手来。\n");
	
	if (me->query_condition("hawk_claw"))
		return notify_fail("你正流血不止，拴住苍鹰还活得了？还是快把它放下吧(drop)。\n");
	
	message_vision("$N趁$n忙着吃狼肉脯，轻轻地把一段小铁链系在它脚上。\n",me,hawk);
	destruct(chain);
	
	hawk->set("marks/feeding",0);
	remove_call_out("eatMeat");
	
	//now we can stick a new hawk with the player
		
	new_hawk = new(__DIR__"hawk_trained");
	new_hawk->set("marks/owner",me->name());
	if	(!new_hawk->move(me))
		message_vision("$n像受了惊，一展翅膀飞上天空，转眼间消失在白云间。\n",me,hawk);
		
	destruct(hawk);	
	return 1;

}