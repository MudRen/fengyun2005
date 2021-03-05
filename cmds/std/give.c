// give.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//
// Last modification:
//		- 07/17/2001 by Daniel Q. Yu.
//			* Fix messages for give command.
//			* Changed the log message.

inherit F_CLEAN_UP;
string *files;

int do_give(object me, object obj, object who);

void create() {
	seteuid(getuid());
	files=explode(read_file("/adm/etc/give_deny"),"\n");
}

int main(object me, string arg) {
	string target, item;
	object obj, who, *inv, obj2;
	int i, amount;

	if(!arg) {
		return notify_fail("你要给谁什麽东西？\n");
	}

	if(sscanf(arg, "%s to %s", item, target)==2 || sscanf(arg, "%s %s", target, item)==2 );
	else {
		return notify_fail("你要给谁什麽东西？\n");
	}

	if(!objectp(who = present(target, environment(me)))) {
		return notify_fail("这里没有这个人。\n");
	}

	if(who->query_temp("is_unconcious"))
		return notify_fail("此人现在无法接受你的物件。\n");


	if ( userp(who) && sizeof(all_inventory(who))>=26)
		return notify_fail("此人已经带著太多东西了！\n");

	if(!living(who)) {
		return notify_fail("这里没有这个人。\n");
	}

	if(me == who) {
		return notify_fail("你左手要给右手东西吗？\n");
	}

	if(userp(me) && who->query("env/no_give"))
		return notify_fail("此人不愿接受任何外来物品。\n");
		
	if (environment(me)->query("tianji_square")) {
		if (userp(who) && userp(me))
			return notify_fail("天机广场人多眼杂，不适合作交易，换个地方吧。\n");
	}
	
	if(sscanf(item, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )
			return notify_fail("你身上没有这样东西。\n");
		if( obj->query("no_drop") && userp(who))
			return notify_fail("这样东西不能随便给人。\n");
		if( !obj->query_amount() )
			return notify_fail( obj->name() + "不能被分开给人。\n");
		if( amount < 1 )
			return notify_fail("东西的数量至少是一个。\n");
		if( amount > obj->query_amount() )
			return notify_fail("你没有那麽多的" + obj->name() + "。\n");
		else if( amount == (int)obj->query_amount() )
			return do_give(me, obj, who);
		else {
			obj->set_amount( (int)obj->query_amount() - amount );
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			obj2->set_name(obj->query("name"),obj->parse_command_id_list());
			obj2->set("long",obj->query("long"));
			obj2->set("unit",obj->query("unit"));


			if(!do_give(me, obj2, who)) {
				obj->set_amount( (int)obj->query_amount() + amount );
				return 0;
			}
			return 1;
		}
	} else if(item=="all") {
		if (environment(me)->query("tianji_square")) 
			return notify_fail("天机老人说：慢慢来，这么多东西搞得我眼都花了。\n");
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++) {
			do_give(me, inv[i], who);
		}
		return 1;
	} else {
		if(!objectp(obj = present(item, me)))
			return notify_fail("你身上没有这样东西。\n");
		return do_give(me, obj, who);
	}
}

int do_give(object me, object obj, object who) {
	string str, name;
	object your_item, *your_inv;
	int j;

	if(obj->query("no_drop")&& userp(who)) {
		return notify_fail("这样东西不能随便给人。\n");
	}

	if (userp(who) && sizeof(all_inventory(who))>=26)
		return notify_fail("此人已经带著太多东西了！\n");


//	not a good fix.. but a temperory one to fix making weapon/armor then give to NPCs.
	if (obj->query("owner"))
		return notify_fail("私有物品不能随便给人。\n");


	if ( obj->query("lore")) {
		your_inv = all_inventory(who);
		for(j=0;j<sizeof(your_inv);j++){
			your_item = your_inv[j];
			if(obj->query("name")==your_item->query("name")
				&& your_item->query("lore"))
			return notify_fail("这样东西他最多只能拥有一件。\n");
			}
	}

	// check for dynamic_quests
	if(obj->query("dynamic_quest") && TASK_D->quest_reward(me,who,obj)) {
		return 1;
	}
		// check for flower delivery quests

	if(obj->query("delivery") && QUESTS_D->flower_delivery_reward(me,who,obj)) {
		return 1;
	}

		// check for perform reward
	if(obj->query("pfm_r1") && F_ABILITY->pfm_r1_book_reward(me,who,obj)) {
		return 1;
	}
		
	name = file_name(who);
	message_vision("$N递给$n一" + obj->query("unit") + obj->name() + "。\n", me, who);
	if(!interactive(who)) {
		if(!who->accept_object(me, obj)) {
			str = query_notify_fail();
			return notify_fail(str? str : who->name() + "并不要你的" + obj->name() + "。\n");
		}
	}
//	A reminder here, don't destroy "who" in accept_object(). or it will cause error.
	
	log_file("ERROR_DEBUG",sprintf("target %s is destroyed when executing give command.\n",name));
	
	if(member_array(base_name(obj),files)!=-1) {
		str = sprintf("(%s) \n%s(%s) give %s(%s) to %s(%s)\n", ctime(time()),
			me->name(), userp(me)? me->query("id") : base_name(me),
			obj->name(), base_name(obj),
			who->name(), userp(who)? who->query("id") : base_name(who));
		log_file("GIVE_LOG", str);
	}

	if(!userp(who) && !who->query("can_carry")) {
		destruct(obj);
	} else if(!obj->move(who)) {
		return 0;
	} else if (obj->query("no_transfer"))
		obj->set("no_drop",1);
		
//	write(sprintf("记录是……%O\n",files));
//	write(sprintf("当前物品是：%s\n",base_name(obj)));
//	write(sprintf("是否是记录中的？%d\n",member_array(base_name(obj),files)));

//	if ( wizardp(me) )log_file("GIVE_LOG", str);

	return 1;
}
int help(object me) {
	write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	give <物品名称> to <某人>
      		或 : give <某人> <物品名称>[0m
[0;1;37m────────────────────────────────[0m   

这个指令可以让你将某样物品给别人, 当然, 首先你要拥有这样物品。
如果你不愿意接受外来物品，可以set no_give 1

[0;1;37m────────────────────────────────[0m   
HELP
    );
    return 1;
}
