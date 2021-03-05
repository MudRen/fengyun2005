#include <ansi.h>
inherit NPC;
int check_legal_name(string arg);
int check_legal_id(string arg);
int get_ji_times(object me);

void create()
{
	set_name("张铁匠", ({ "smith zhang","smith","zhang" }));
	set("title", HIR"风云第一锤"NOR);
	set("gender", "男性");
	set("age", 52);
	set("long", "张铁匠一身打铁功夫名不虚传，他打出的铁器经久耐用。\n");
	set("combat_exp", 2000);
	set("attitude", "friendly");
	setup();
	carry_object("/obj/armor/cloth")->wear();
}

void init()
{
	object ob;
	::init();
	if( interactive(ob=this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_ding", "ding");
	add_action("do_xiu", "xiu");
	add_action("do_estimate","estimate");
	add_action("do_rebuild", "rebuild");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) {
		return;
	}
	switch( random(5) ) {
		case 0:
			say( "张铁匠粗声粗气地说道：这位" + RANK_D->query_respect(ob) + "，要什么？\n");
			break;
		case 1:
			say( "张铁匠满脸汗水说道：这位" + RANK_D->query_respect(ob) + "，我太忙了，帮不了你。\n");
			break;
	}
}

int do_estimate(string arg)
{
	object me, weapon, reference;
	int dam, total;

	me = this_player();
	if( !arg ) {
		return notify_fail("你要修什么？\n");
	}
	weapon = present(arg, me);
	if( !objectp(weapon) ) {
		return notify_fail("你要修什么？\n");
	}
	if( !weapon->query("weapon_prop") ) {
		return notify_fail("张铁匠说：我只会修兵器，其他的可不成。\n");
	}
	if( !weapon->query("owner") ) {
		// 通用武器修理。
		seteuid(getuid());
		reference = new(base_name(weapon));
		if( !reference ) {
			message_vision("$N看了看$n手中的" + weapon->name() + "说道：这个不值得一修。\n", this_object(), me);
			return 1;
		}
		// 有的物件用的是clone物品更名。。。没法修。
		if( reference->query("name") != weapon->query("name") ) {
			message_vision("$N看了看$n手中的" + weapon->name() + "说道：我这儿没有原图，恐怕修不好。\n", this_object(), me);
			return 1;
		}
		dam = reference->query("weapon_prop/damage") - weapon->query("weapon_prop/damage");
		if( dam <= 0 ) {
			return notify_fail("你的武器没有损坏。\n");
		} else if( reference->query("weapon_prop/damage") < 25 ) {
			total = 1; // 如果是一般Quest用的冬冬，1 gold per fix。
		} else {
			total = dam *3;	//如果你想用这样武器,嘿嘿不客气敲一把竹杠。
		}
		destruct(reference);
	} else {
		// 自制武器修理：
		dam = weapon->query("base_damage") - weapon->query("weapon_prop/damage");
		if( dam <= 0) {
			return notify_fail("你的武器没有损坏。\n");
		} else {
			total = dam;	// 1 gold per damage fix for self-made weapon.
		}
		// 杀伤力=150，所以最多不超过base_damage/4
		if( total > weapon->query("base_damage")/4 ) {
			total = weapon->query("base_damage")/4;
		}
	}
	tell_object(me,"张铁匠说，修理此把兵器需要黄金"+ chinese_number(total) + "两，如果确定，请用xiu指令。\n");
	return 1;
}

int do_xiu(string arg) {
	object me, weapon, reference;
	int dam, i, total;

	me = this_player();
	if( !arg ) {
		return notify_fail("你要修什么？\n");
	}
	weapon = present(arg, me);
	if( !objectp(weapon) ) {
		return notify_fail("你要修什么？\n");
	}
	if( !weapon->query("weapon_prop") ) {
		return notify_fail("张铁匠说：我只会修兵器，其他的可不成。\n");
	}
	if( !weapon->query("owner") ) {
		// 通用武器修理。
		seteuid(getuid());
		reference = new(base_name(weapon));
		if( !reference ) {
			message_vision("$N看了看$n手中的" + weapon->name() + "说道：这个不值得一修。\n", this_object(), me);
			return 1;
		}
		// 有的物件用的是clone物品更名。。。没法修。
		if( reference->query("name") != weapon->query("name") ) {
			message_vision("$N看了看$n手中的" + weapon->name() + "说道：我这儿没有原图，恐怕修不好。\n", this_object(), me);
			return 1;
		}
		dam = reference->query("weapon_prop/damage") - weapon->query("weapon_prop/damage");
		if( dam <= 0) {
			return notify_fail("你的武器没有损坏。\n");
		} else if( reference->query("weapon_prop/damage") < 25)	{
			i = 1; // 如果是一般Quest用的冬冬，1 gold per fix。
		} else {
			i = dam *3; // 如果你想用这样武器,嘿嘿不客气敲一把竹杠。
		}
		destruct(reference);
	} else {
		// 自制武器修理：
		dam = weapon->query("base_damage") - weapon->query("weapon_prop/damage");
		if(dam <= 0) {
			return notify_fail("你的武器没有损坏。\n");
		} else {
			i = dam;	// 1 gold per damage fix for self-made weapon.
		}
		// 杀伤力=150，所以最多不超过base_damage/4
		if( i > weapon->query("base_damage")/4 ) {
			i = weapon->query("base_damage")/4;
		}
	}
	if( !me->query("env/e_money") ) {
		total = MONEY_D->affordable(me, i*10000, 1);
		if(!total) {
			return notify_fail("你身上没有足够的金子，需要金子" + chinese_number(i) + "两。\n");
		}
		MONEY_D->pay_him(me, total-i*10000);
	} else {
		if( me->query("deposit") < i*10000) {
			return notify_fail("你银行里没有足够的金子，需要金子" + chinese_number(i) + "两。\n");
		}
		me->add("deposit",-i*10000);
	}
	if( weapon->query("equipped") == "wielded" ) {
		weapon->unequip();
	}
	weapon->add("weapon_prop/damage", dam);
	weapon->set("item_damaged", 0);
	message_vision("$N接过$n手中的" + weapon->name() + "用锤子敲打了几下。\n", this_object(), me);
	message_vision("“好了！”$N递还" + weapon->name() + "给$n。\n", this_object(), me);
	tell_object(me,"修理武器共用去黄金"+chinese_number(i)+"两。\n");
	if( weapon->query("orig_name") ) {
		weapon->set("name", weapon->query("orig_name"));
	}
	if( weapon->query("owner") ) {
		weapon->save();
	}
	return 1;
}


int do_ding(string arg)
{
	string ctype, cname, ccolor, cid;
	object ob, me;
	string id, newfile,filename,timestamp;
	int total;

	me = this_player();
	id = me->query("id");

	if( !arg || sscanf(arg,"%s %s %s %s",ctype,ccolor,cname,cid ) != 4 ) {
		return notify_fail("指令格式：ding <type> <color> <name> <English name>\n");
	}
	if( me->is_busy() ) {
		return notify_fail("你上一个动作还没有完成。\n");
	}
	if( me->query("combat_exp") < 50000 ) {
		return notify_fail("打造物品至少需要经验等级为五。\n");
	}
	if( (int)me->query("created_item") > 0 ) {
		return notify_fail("你最多只能拥有一件自制物品。\n");
	}

	total = MONEY_D->affordable(me, 100000, 1);
	if( !total ) {
		return notify_fail("你身上没有十两金子。\n");
	}
	if( sizeof(all_inventory(me)) >= 14 ) {
		return notify_fail("你身上的东西太多了，我打了兵器你也没法拿。\n");
	}
	if( !check_legal_name(cname) ) {
		return notify_fail("");
	}
	if( !check_legal_id(cid) ) {
		return notify_fail("");
	}

	if( ccolor != "$BLK$" &&
		ccolor != "$NOR$" &&
		ccolor != "$RED$" &&
		ccolor != "$GRN$" &&
		ccolor != "$YEL$" &&
		ccolor != "$BLU$" &&
		ccolor != "$MAG$" &&
		ccolor != "$CYN$" &&
		ccolor != "$WHT$" &&
		ccolor != "$NOR$" &&
		ccolor != "$HIR$" &&
		ccolor != "$HIG$" &&
		ccolor != "$HIY$" &&
		ccolor != "$HIB$" &&
		ccolor != "$HIM$" &&
		ccolor != "$HIC$" &&
		ccolor != "$HIW$" 
	)
	return notify_fail("不知你要什么颜色．\n");
	ccolor = replace_string(ccolor, "$BLK$", "BLK");
	ccolor = replace_string(ccolor, "$RED$", "RED");
	ccolor = replace_string(ccolor, "$GRN$", "GRN");
	ccolor = replace_string(ccolor, "$YEL$", "YEL");
	ccolor = replace_string(ccolor, "$BLU$", "BLU");
	ccolor = replace_string(ccolor, "$MAG$", "MAG");
	ccolor = replace_string(ccolor, "$CYN$", "CYN");
	ccolor = replace_string(ccolor, "$WHT$", "WHT");
	ccolor = replace_string(ccolor, "$HIR$", "HIR");
	ccolor = replace_string(ccolor, "$HIG$", "HIG");
	ccolor = replace_string(ccolor, "$HIY$", "HIY");
	ccolor = replace_string(ccolor, "$HIB$", "HIB");
	ccolor = replace_string(ccolor, "$HIM$", "HIM");
	ccolor = replace_string(ccolor, "$HIC$", "HIC");
	ccolor = replace_string(ccolor, "$HIW$", "HIW");
	ccolor = replace_string(ccolor, "$NOR$", "NOR");
	seteuid(ROOT_UID);
	switch( ctype ) {
		case "axe":
			newfile = read_file("/obj/selfmake/weapons/axe.o");
			break;
		case "blade":
			newfile = read_file("/obj/selfmake/weapons/blade.o");
			break;
	/*	case "dagger":
			newfile = read_file("/obj/selfmake/weapons/dagger.o");
			break;
		case "fork":
			newfile = read_file("/obj/selfmake/weapons/fork.o");
			break;*/
		case "hammer":
			newfile = read_file("/obj/selfmake/weapons/hammer.o");
			break;
		case "staff":
			newfile = read_file("/obj/selfmake/weapons/staff.o");
			break;
		case "sword":
			newfile = read_file("/obj/selfmake/weapons/sword.o");
			break;
		case "whip":
			newfile = read_file("/obj/selfmake/weapons/whip.o");
			break;
		case "spear":
			newfile = read_file("/obj/selfmake/weapons/spear.o");
			break;
	/*	case "banzhi":
			newfile = read_file("/obj/selfmake/weapons/fist.o");
			break;*/
		default:
			return notify_fail("这里不会做你要的东西．\n");
	}
	timestamp = sprintf("%c%c%c%c%c%c%c", 'a'+random(20), 'a'+random(20), 'a'+random(20), 'a'+random(20), 'a'+random(20), 'a'+random(20), 'a'+random(20));
	newfile = replace_string( newfile, "订作的", cname);
	newfile = replace_string( newfile, "order", cid);
	newfile = replace_string( newfile, "fengyun", id);
	newfile = replace_string( newfile, "COR", ccolor);
	newfile = replace_string( newfile, "STAMP", timestamp);
	filename = DATA_DIR+"login/" + id[0..0] + "/" + id + "/" + id +timestamp + ".c";

	if( !write_file(filename, newfile,1) ) {
		return 0;
	}
	ob = new(filename);
	ob->set("weight", 3000);
	ob->set("rigidity", 50);
	ob->set("weapon_prop/damage", 10);
	ob->set("base_damage", 10);
	ob->set("enhance_time", 0);
	ob->set("orig_name", ob->query("name"));
	ob->save();
	ob->restore();
	if( ob->move(me) ) {
		MONEY_D->pay_him(me, total-100000);
		me->add("created_item", 1);
		me->start_busy(1);
		write("张铁匠点点头，从身边抓起一块破铜烂铁废原胚，打造成一"+ob->query("unit")+ ob->name()+"\n");
		message_vision(YEL"$N递给了$n一" + ob->query("unit") + ob->name() + YEL"，长叹了一口气：“我做的兵器都是有灵性的，\n"NOR, this_object(), me);
		message_vision(YEL"也不知当今世上有几个人能够明白。”\n"NOR, this_object());
		seteuid(getuid());
		return 1;
	} else {
		destruct(ob);
		tell_object(me,WHT"制造武器发生错误，请尽快通知巫师。\n"NOR);
	}
	return 0;
}

int do_rebuild(string arg)
{
	string ctype, cname, ccolor, cid;
	object ob, me;
	string id, newfile, filename, timestamp;
	int ji_times;

	me = this_player();
	id = me->query("id");

	if( !arg || sscanf(arg,"%s %s %s %s",ctype, ccolor, cname, cid) != 4 ) {
		return notify_fail("指令格式：rebuild <type> <color> <name> <English name>\n");
	}

	if( me->is_busy() ) {
		return notify_fail("你上一个动作还没有完成。\n");
	}

	if( me->query("combat_exp") < 50000 ) {
		return notify_fail("打造物品至少需要经验等级为五。\n");
	}

	if( (int)me->query("created_item") <= 0 ) {
		return notify_fail("你没有打造过自制物品，怎么恢复？\n");
	}

	if( (int)me->query("rebuilt_item") > 0 ) {
		return notify_fail("你只能恢复一件自制物品。\n");
	}

	if( sizeof(all_inventory(me)) >= 14 ) {
		return notify_fail("你身上的东西太多了，我打了兵器你也没法拿。\n");
	}

	if( !check_legal_name(cname) ) {
		return notify_fail("");
	}

	if( !check_legal_id(cid) ) {
		return notify_fail("");
	}

	if( ccolor != "$BLK$" && 
		ccolor != "$NOR$" &&
		ccolor != "$RED$" &&
		ccolor != "$GRN$" &&
		ccolor != "$YEL$" &&
		ccolor != "$BLU$" &&
		ccolor != "$MAG$" &&
		ccolor != "$CYN$" &&
		ccolor != "$WHT$" &&
		ccolor != "$NOR$" &&
		ccolor != "$HIR$" &&
		ccolor != "$HIG$" &&
		ccolor != "$HIY$" &&
		ccolor != "$HIB$" &&
		ccolor != "$HIM$" &&
		ccolor != "$HIC$" &&
		ccolor != "$HIW$" 
	)
	return notify_fail("不知你要什么颜色．\n");
	ccolor = replace_string(ccolor, "$BLK$", "BLK");
	ccolor = replace_string(ccolor, "$RED$", "RED");
	ccolor = replace_string(ccolor, "$GRN$", "GRN");
	ccolor = replace_string(ccolor, "$YEL$", "YEL");
	ccolor = replace_string(ccolor, "$BLU$", "BLU");
	ccolor = replace_string(ccolor, "$MAG$", "MAG");
	ccolor = replace_string(ccolor, "$CYN$", "CYN");
	ccolor = replace_string(ccolor, "$WHT$", "WHT");
	ccolor = replace_string(ccolor, "$HIR$", "HIR");
	ccolor = replace_string(ccolor, "$HIG$", "HIG");
	ccolor = replace_string(ccolor, "$HIY$", "HIY");
	ccolor = replace_string(ccolor, "$HIB$", "HIB");
	ccolor = replace_string(ccolor, "$HIM$", "HIM");
	ccolor = replace_string(ccolor, "$HIC$", "HIC");
	ccolor = replace_string(ccolor, "$HIW$", "HIW");
	ccolor = replace_string(ccolor, "$NOR$", "NOR");
	seteuid(ROOT_UID);
	switch( ctype ) {
			case "axe":
					newfile = read_file("/obj/selfmake/weapons/axe.o");
					break;
			case "blade":
					newfile = read_file("/obj/selfmake/weapons/blade.o");
					break;
/*			case "dagger":
					newfile = read_file("/obj/selfmake/weapons/dagger.o");
					break;
			case "fork":
					newfile = read_file("/obj/selfmake/weapons/fork.o");
					break;*/
			case "hammer":
					newfile = read_file("/obj/selfmake/weapons/hammer.o");
					break;
			case "staff":
					newfile = read_file("/obj/selfmake/weapons/staff.o");
					break;
			case "sword":
					newfile = read_file("/obj/selfmake/weapons/sword.o");
					break;
			case "whip":
					newfile = read_file("/obj/selfmake/weapons/whip.o");
					break;
			case "spear":
					newfile = read_file("/obj/selfmake/weapons/spear.o");
					break;
/*			case "banzhi":
					newfile = read_file("/obj/selfmake/weapons/fist.o");
					break;*/
			default:
				return notify_fail("这里不会做你要的东西．\n");
	}
	timestamp = sprintf("%c%c%c%c%c%c%c", 'a'+random(20), 'a'+random(20), 'a'+random(20), 'a'+random(20), 'a'+random(20), 'a'+random(20), 'a'+random(20));
	newfile = replace_string( newfile, "订作的", cname);
	newfile = replace_string( newfile, "order", cid);
	newfile = replace_string( newfile, "fengyun", id);
	newfile = replace_string( newfile, "COR", ccolor);
	newfile = replace_string( newfile, "STAMP", timestamp);
	filename = DATA_DIR + "login/" + id[0..0] + "/" + id + "/" + id + timestamp + ".c";

	if( !write_file(filename, newfile,1) ) {
		return 0;
	}

	ob = new(filename);
	ob->set("weight", 3000);
	ob->set("rigidity", 50);
	ob->set("weapon_prop/damage", 10);
	ob->set("base_damage", 10);
	ob->set("enhance_time", 0);
	ob->set("orig_name", ob->query("name"));

	ji_times = (int)get_ji_times(me);
	ob->add("weapon_prop/damage", 10*ji_times);
	ob->add("base_damage", 10*ji_times);
	ob->set("weight", ob->query("weight") + 300*ji_times);
	ob->add("rigidity", 50*ji_times);
	ob->save();
	ob->restore();
	if( ob->move(me) ) {
		me->add("rebuilt_item", 1);
		me->start_busy(1);
		write("张铁匠点点头，从身边抓起一块破铜烂铁废原胚，打造成一"+ob->query("unit")+ ob->name()+"\n");
		message_vision(YEL"$N递给了$n一" + ob->query("unit") + ob->name() + YEL"，长叹了一口气：“我做的兵器都是有灵性的，\n"NOR, this_object(), me);
		message_vision(YEL"也不知当今世上有几个人能够明白。”\n"NOR, this_object());
		seteuid(getuid());
		return 1;
	} else {
		destruct(ob);
		tell_object(me, WHT"制造武器发生错误，请尽快通知巫师。\n"NOR);
	}
	return 0;
}


int check_legal_name(string name)
{
	int i;
	i = strlen(name);
	if( (strlen(name) < 2) || (strlen(name) > 40 ) ) {
		write("对不起，中文名字必须是一到二十个中文字。\n");
		return 0;
	}
	while(i--) {
		if( name[i]<=' ' ) {
			write("对不起，中文名字不能用控制字元。\n");
			return 0;
		}
		}
		if(!is_chinese(name) ) {
			write("对不起，名字必需是中文。\n");
			return 0;
		}	
	return 1;
}


int check_legal_id(string name)
{
	int i;
	i = strlen(name);
	if( (strlen(name) < 3) || (strlen(name) > 20 ) ) {
		write("对不起，英文名字必须是三到二十个字。\n");
		return 0;
	}
	return 1;
}

int get_ji_times(object me)
{
	int ntimes = 0;
	if( me->query("ji/" + "12") ) {
		ntimes++;
	}
	if( me->query("ji/" + "19") ) {
		ntimes++;
	}
	if( me->query("ji/" + "26") ) {
		ntimes++;
	}
	if( me->query("ji/" + "33") ) {
		ntimes++;
	}
	if( me->query("ji/" + "40") ) {
		ntimes++;
	}
	if( me->query("ji/" + "47") ) {
		ntimes++;
	}
	if( me->query("ji/" + "54") ) {
		ntimes++;
	}
	if( me->query("ji/" + "61") ) {
		ntimes++;
	}
	if( me->query("ji/" + "68") ) {
		ntimes++;
	}
	if( me->query("ji/" + "80") ) {
		ntimes++;
	}
	if( me->query("ji/" + "90") ) {
		ntimes++;
	}
	if( me->query("ji/" + "110") ) {
		ntimes++;
	}
	if( me->query("ji/" + "120") ) {
		ntimes++;
	}
	if( me->query("ji/" + "130") ) {
		ntimes++;
	}
	if( me->query("ji/" + "135") ) {
		ntimes++;
	}
	ntimes += (int)me->query("ji2_times");
	return ntimes;
}