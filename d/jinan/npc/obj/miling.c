#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW"密令"NOR, ({ "secret order" }) );
	set_weight(1972);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "张");
		set("material", "paper");
        set("long", "
一道提押犯人上堂的密令，还未盖知府大印，没有任何可以验证此物
合法的签名。你可以把它亮给别人看（show）\n");
	}
    ::init_item();
}

void init()
{
        add_action("do_show", "show");
        add_action("do_look","look");
}
void del_show_order(object ob)
{
	if (ob){
		ob->delete_temp("show_order");
		if (environment(ob)->query("jinan_prison"))
			tell_object(ob,YEL"你听到一阵嘈杂的脚步声，似乎天牢守卫已经起了疑心。\n"NOR);
	}	
	destruct(this_object());
	return;
}

int do_look (string arg)
{
	string str;
	str="一道提押犯人上堂的密令，\n";
	if (arg=="secret order")
	{

	if (this_object()->query("sealed")!=1)
		str += "还未盖知府大印，\n";
	else 
		str += "上面盖了一个知府大印，\n";

	if (crypt(query("real")+"3","wHGJZgPRCuvVs") == "wHGJZgPRCuvVs")
		str += "上面龙飞凤舞地写著几个大字：济南殷。\n";
	else 
		str += "没有任何可以验证此物合法的签名。\n";

	str += "你可以把它亮给别人看（show）\n";
	tell_object(this_player(),str);
	return 1;
	}
	return 0;
}	

int do_show(string arg)
{
	object obj,*inv;
	int i;

	if (environment(this_object())!=this_player())
		return 0;
		
	if (!arg)
		return notify_fail(" Show 给谁看？\n");
		
	if (!objectp(obj=present(arg,environment(this_player()))))
		return notify_fail("你要把密令拿给谁看？\n");
	if (!living(obj))
		return notify_fail("嗯....你得先把" + obj->query("name") +"弄醒再说。\n");
	
	message_vision("$N把"+this_object()->query("name")+"出示给$n看。\n",this_player(),obj);

	if (obj->query("prison_guard"))
	{
			if (this_object()->query("sealed")==1)
			{

				if ( crypt(query("real")+"3","wHGJZgPRCuvVs") == "wHGJZgPRCuvVs")
				{
							if (this_player()->query("combat_exp")<1600000) 
							{
								message_vision("$N用怀疑的眼光看了看$n说：就凭你这两下子，也能押解犯人？\n",obj,this_player());
								return notify_fail("天牢守卫看来不信任你。（至少需等级40）\n");
							}
							message_vision("$N仔仔细细看了看密令，神色凝重道：犯人就在里面。\n",obj);
							message_vision("$N打开铁门上的大铜锁，拱手示意道：大人，请往里走。\n",obj);

							if (REWARD_D->riddle_check(this_player(),"浴血天牢") == 1) 
								REWARD_D->riddle_set(this_player(),"浴血天牢",2);



							environment(obj)->do_open();
							if (obj->query("prison_guard")==1)
								this_player()->set_temp("show_order",1);
							else{
								this_object()->move(obj);
								call_out("del_show_order",300 , this_player());
							}
				}
				else
				{
					message_vision("$N仔细一看，脸色陡沉：没有殷知府的签名，从哪里偷了个印章便想蒙混过关？\n$N说道：嘿嘿，我们见多了！\n",obj);
			message_vision(HIR"\n突然从暗中跳出来几个捕快对$N嚷道：之前这么劫了牢，现在还敢来！我们埋伏在这里好久了！\n"NOR, this_player());
			message_vision(HIR"捕快对$N狞笑道：如今人证俱在，乖乖跟我们走吧！ \n"NOR,this_player());
			message_vision(HIR"捕快将$N押向大牢。\n\n"NOR,this_player());
			this_player()->set("vendetta/authority", 1);
			this_player()->move("/d/jinan/laofang2");
			message_vision(HIY"$N被搜空所有的东西，一脚踢进了牢房！\n"NOR,this_player());
			inv = all_inventory(this_player());
			for(i=0; i<sizeof(inv); i++) 
            if (inv[i] != this_object())
            {
				if (inv[i]->query("id")=="treasure box")	
					inv[i]->do_qqsave(this_player());
            	else if (!inv[i]->query("no_drop"))
            		destruct(inv[i]);
            }
			destruct(this_object());
			return 1;					
			}

		}
		else
		{
			message_vision("$N仔细一看，脸色陡沉：竟然妄图蒙混过关！来人啊！有歹人劫狱～～\n",obj);
			obj->do_alert(this_player());
		}
	}
	else if (obj->query("forger"))
	{
		message_vision("$N双眼发出奇怪的热切的光芒，似酗酒的人忽然闻到了陈年的杜康。	\n",obj);
		obj->set_temp("showed_miling",1);	
	}
	else{
		if (!userp(obj)){
			if (obj->query("vendetta_mark")=="authority"){
				message_vision("$N瞪了$n一眼，说道：此是官府之物，你从何处得来？\n",obj,this_player());
			}
			else{
				message_vision("$N好像对"+this_object()->query("name")+"没什么兴趣。\n",obj);
			}
		}
	}

	return 1;
}
