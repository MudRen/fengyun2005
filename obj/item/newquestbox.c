// questbox.c By Silencer@fy2005 workgroup, Nov.2005
/*
	此容器专为存储ＱＵｅｓｔ物品，存入物品不以实体存在，只能用于Ｑｕｅｓｔ交回
	此容器内容以文件存在于玩家目录中，为节省读写过程：
		读：仅发生在ｐｌａｙｅｒ从ＮＰＣ处取出此容器时，同时销毁该文件
		写：仅发生在ｐｌａｙｅｒ主动存贮容器，或者退出时，写后将将此容器实体销毁
	在任何情况下，文件与容器只能有一件存在。
	其目的在于：
	（１）免除大部分需要在线保存ｑｕｅｓｔ物品的需要	
	（２）节省系统中大量无谓容器和ｄｕｍｍｙ的资源
	如果只考虑到自身ｉｄ，没有任何需要再保持长期在线。
	
	可能后果：
	（１）该容器中的物品只进不出，	减少ｑｕｅｓｔ物品在不同玩家间的流通，不一定是件坏事
	（２）由于它十分便利可靠，高等级的玩家可替低等级的玩家大量存贮ｑｕｅｓｔ物品，			

	Old codes 中曾经call过qqsave的文件有
	/d/jinan/npc/obj/miling
	/obj/biaoyin
	/d/fugui/npc/beauty
	/cmds/usr/quit
	/adm/daemons/moneyd
*/

#include <ansi.h>

inherit ITEM;

int do_qput(string arg);
int do_qqput(object me, object obj);
int do_qsave();
varargs int do_qqsave(object me);
int do_qdiscard(string arg); 
varargs int do_qqdiscard(string arg, object me, int silent);

string replace_color(string arg);

// mapping items=([]);
/* 格式为：
items = ([
	铁剑：	5
	舍利子： 1
]);	
*/

void create() {
	set_name("玄灵玉盒", ({ "treasure box","treasurebox",}) );
	set("long","
一个闪烁着淡淡玉色的盒子，顶端龙飞凤舞地写着四个大字
『风云依旧』。这是风云中专门用来存贮天机老人任务物品
的宝盒。（具体使用方法请参看ｈｅｌｐ　ｇａｍｅ中的天
机任务篇）放入此箱中的物品将只能用于Ｑｕｅｓｔ，而
不再能取出。

此玉盒支持以下指令：
（１）qlook 察看玄灵玉盒物品列表
（２）qput <某物英文ｉｄ> 把物品放入玄灵玉盒
（３）qdiscard <某物中文名字> 永久丢弃某物
（４）qdiscard <数目> <中文名> 丢弃一定数目的物品
（５）qdiscard all 清除所有玉盒中的物品
（６）qsave　把玉盒交还给系统存储起来

在天机老人处可使用
（７）qreturn 自动搜寻玉盒交还自身任务
（８）qreturn <某物中文名> 指定交还某天机任务物品

\n");
	set("unit", "个");
	set("lore", 1);
	set("quest_box",1);
	set("no_split",1);
	set("no_drop", 1);
}


void init() {
	object ob;

	if(this_player() && environment()==this_player() ) {
		set("owner_id",this_player()->query("id"));
		set_name( this_player()->name(1) + "的玄灵玉盒", ({ "treasure box","treasurebox" }) );
		add_action("do_qput", "qput");
		add_action("do_qlook", "qlook");
		add_action("do_qdiscard", "qdiscard");
		add_action("do_qsave", "qsave");
	}
}


int do_qput(string arg) {
	
	object *inv, me, obj, obj2;
	int amount;
	string item;
	
	if (!arg)
		return notify_fail("你要往玄灵玉盒里放什么东西？\n");
		
	me = this_player();
	inv = all_inventory(me);
	
	if(sscanf(arg, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )
			return notify_fail("你身上没有这样东西。\n");
		if( obj->query("no_drop"))	// Enough? Qput == Burn I guess
			return notify_fail("这样东西不能放入玄灵玉盒里。\n");
		if (obj->query("dynamic_quest"))
			return notify_fail("TASK放进去你怎么还啊？\n");
		if( !obj->query_amount() )
			return notify_fail( obj->name() + "不能被分开放。\n");
		if( amount < 1 )
			return notify_fail("东西的数量至少是一个。\n");
		if( amount > obj->query_amount() )
			return notify_fail("你没有那麽多的" + obj->name() + "。\n");
		else if( amount == (int)obj->query_amount() )
			return do_qqput(me, obj);
		else {
			obj->set_amount( (int)obj->query_amount() - amount );
			seteuid(getuid());
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			obj2->set_name(obj->query("name"),obj->parse_command_id_list());
			obj2->set("long",obj->query("long"));
			obj2->set("unit",obj->query("unit"));
			if(!do_qqput(me, obj2)) {
				obj->set_amount( (int)obj->query_amount() + amount );
				return 0;
			}
			if (obj2) destruct(obj2);
			return 1;
		}
	} else {
		if(!objectp(obj = present(arg, me)))
			return notify_fail("你身上没有这样东西。\n");
		return do_qqput(me, obj);
	}
	
}


int do_qqput(object me, object obj)
{
	string prep,*dir, name;
	int container_size, amount,index;
	mapping items;
	
    if(obj->query("no_drop") || obj->query("no_get")||obj->query("lore"))
    	return notify_fail("你不能将此物放到玄灵玉盒中。\n");
	
	if (obj->query("dynamic_quest"))
		return notify_fail("TASK放进去你还怎么还啊？\n");
			
	if (obj == this_object())
		return notify_fail("放到自己里面？恐怕不行。\n");
	
	name = obj->query("name");	// We use Chinese Name to index Items.
	
	items = me->query_qitems();
	
	if (mapp(items)) {
		dir = keys(items);
		index = member_array(name, dir);
		container_size = 100;
		//　允许放入已有的东西，即使已满
		if ( index == -1 && sizeof(items)>= container_size)	
			return notify_fail( "玄灵玉盒里面最多只能放" + chinese_number(container_size)+"类物品。\n");
	}
	
	prep = "放进玄灵玉盒里面";

	message_vision( sprintf("$N将一%s%s%s。\n",
			obj->query("unit"), obj->name(), prep),
			me );
	amount = obj->query_amount()>0? obj->query_amount(): 1;

	me->add_qitems(name, amount);	
	destruct(obj);
	return 1;
}

int do_qlook(){
	int i,j,k,extra,num;
	string *list,outstring;
	mapping items;
	
	if (this_object()->query("timer/op") + 1 > time()) {
		write("为节省系统资源，玄灵玉盒命令不能连续操作，请等待一秒钟。\n");
		return 1;
	}		
	this_object()->set("timer/op", time());
	
	items = this_player()->query_qitems();		
	num = sizeof(items);
	
	write(WHT"\t  " + name()+ "中的物品清单（"+num+"/100）\n"NOR);
    write(HIR BLK"────────────────────────────────\n"NOR);

    if (!num)	write (HIR "　　空空如也，大肚能容天下万物。\n"NOR);
    else
    {
		list = keys(items);
		for(i=0; i<num; i++){
			k = 0;
			extra = 0;
			for(j=0; j<strlen(list[i]); j++) {
				if(list[i][j] == ESC[0]) {
					k = 1;	
				}
				if(k == 1) {
					extra++;
				}
				if(list[i][j] == 'm') {
					k = 0;	
				}
			}					      			
        	if (i%2==0){
        		outstring = sprintf("%-*s %5d│", 
        					22+extra,
        					list[i],
        					items[list[i]]);
        		if (i==num-1)
        			outstring +="\n";
        	}			
        	else
        		outstring = sprintf("%-*s %5d\n", 
        					22+extra,
        					list[i],
        					items[list[i]]);
        	write(outstring);
        }
    }
    write(HIR BLK"────────────────────────────────\n"NOR);
    
	return 1;
}

//	THe following two functions are not needed anymore, it's just for campability with old codes
int do_qsave(){
	object me;
	me = this_player();	
	do_qqsave(me);
	return 1;
}

varargs int do_qqsave(object me){	
	tell_object(me,"玄灵玉盒由系统自动保存，需要时请至鹦鹉阁上官雪儿处取出。\n");
	destruct(this_object());
	return 1;
}

// DON"T CALL THIS FUCTION FROM OUTSIDE
// it can't garantee item will be deleted.
int do_qdiscard(string arg) {
	object me;
	me = this_player();
	
	if (this_object()->query("timer/op") + 2> time()) {
		write("为节省系统资源，玄灵玉盒命令不能连续操作，请等待２秒钟。\n");
		return 1;
	}
	this_object()->set("timer/op", time());
	
	do_qqdiscard(arg, me, 0);	
	return 1;
}

// when call this from outside, make sure the item exists yourself!
varargs int do_qqdiscard(string arg, object me, int silent) {
	int num, amount, amount1, index, i;
	string item,*dir;
	mapping items;
	
	if(!arg){
		tell_object(me,"你要丢弃哪一件物品？\n");
		return 0;
	}
	
	if (arg == "all") {
		me->clear_items();
		tell_object(me,"玄灵玉盒清理完毕。。。。所有物品被删除。\n");
		return 1;
	}
			
	if(sscanf(arg, "%d %s", amount1, item)==2)
		arg = item;
	else
		amount1 = 1;
	
	if (amount1<=0){
		tell_object(me,"想要丢弃的东西数目必须是正数。\n");
		return 1;
	}
	
	seteuid(getuid());		
	arg = replace_color(arg);
	items = me->query_qitems();
	num = sizeof(items);
	dir = keys(items);
	index = member_array(arg, dir);
	if (index == -1) {		// 做一次无颜色的匹配
		for (i= 0; i<num; i++) {
			if ( arg == "/feature/nada"->ngstr(dir[i])) {
				index = i;
				break;
			}
		}
	}
	
	if (index == -1) {
		tell_object(me,"玄灵玉盒中没有你所要销毁的物件。\n");
		return 0;
	}
	
	amount = items[dir[index]];
	// if amount1 is bigger.. assume ppl wants to delete all
	
	if (me->add_qitems(dir[index],-amount1)) {
		tell_object(me,"玄灵玉盒中的"+arg + "减少了"+chinese_number(amount1)+"个单位。\n");
	}
	else
	{ 
		if (!silent) 	
			tell_object(me,"玄灵玉盒中所有的"+arg+"都被清空了。\n");
	}
	return 1;
}

string replace_color(string ccolor){
		ccolor = replace_string(ccolor, "$BLK$", "[0;30m");
        ccolor = replace_string(ccolor, "$RED$", "[0;31m");
        ccolor = replace_string(ccolor, "$GRN$", "[0;32m");
        ccolor = replace_string(ccolor, "$YEL$", "[0;33m");
        ccolor = replace_string(ccolor, "$BLU$", "[0;34m");
        ccolor = replace_string(ccolor, "$MAG$", "[0;35m");
        ccolor = replace_string(ccolor, "$CYN$", "[0;36m");
        ccolor = replace_string(ccolor, "$WHT$", "[0;37m");
        ccolor = replace_string(ccolor, "$HIR$", "[1;31m");
        ccolor = replace_string(ccolor, "$HIG$", "[1;32m");
        ccolor = replace_string(ccolor, "$HIY$", "[1;33m");
        ccolor = replace_string(ccolor, "$HIB$", "[1;34m");
        ccolor = replace_string(ccolor, "$HIM$", "[1;35m");
        ccolor = replace_string(ccolor, "$HIC$", "[1;36m");
        ccolor = replace_string(ccolor, "$HIW$", "[1;37m");
        ccolor = replace_string(ccolor, "$NOR$", "[2;37;0m");
    return ccolor;
}    
