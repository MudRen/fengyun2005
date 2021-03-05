// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

#include <ansi.h>
inherit NPC;
object ob;

void create()
{
	set_name("老板娘", ({ "clothes lady","lady" }) );
	set("title",HIR"天衣无缝"NOR);
	set("gender", "女性" );
	set("age", 52);
	set("long",
		"老板娘擅长补衣服，补出来的衣服又牢固而且不难看。\n");
	set("inquiry", ([
        	"雪蚕丝":	"这是风云之宝，非有缘无法得到。\n",
             	"乌蚕丝":	"这是风云之宝，非有缘无法得到。\n",
             	"天蚕丝":	"这是风云之宝，非有缘无法得到。\n",
   	]));
	
	set("combat_exp", 2000);
	set("attitude", "friendly");
	setup();
        carry_object("/obj/armor/cloth")->wear();

}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
//	add_action("do_zhi","zhi");	
	add_action("do_xiu","bu");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(5) ) {
		case 0:
			say( "老板娘笑道：这位" + RANK_D->query_respect(ob)
				+ "，你的衣衫看起来好象要补一下了。\n");
			break;
		case 1:
			say( "老板娘说道：这位" + RANK_D->query_respect(ob)
				+ "，你的衣衫都被人砍破了，来补一下吧。\n");
			break;
	}
}

int  do_zhi(string arg)
{
	object me;
	object gold;
	int cost = 1;
	int i,j,base,current, ji_times;
	string id,name ;	
	string file,newfile,filestring;
	me = this_player();
	id = me->query("id");
        
        if( !arg ) return notify_fail("你要织什麽衣物？\n");
        if(me->is_busy())
        	return notify_fail("你上一个动作还没有完成。\n");
        if( !objectp(ob = present(arg, me)) )
        	return notify_fail("你身上没有这样东西。\n");
        if( !ob->query("armor_prop") )
        	return notify_fail("你只能织能穿在身上的东西。\n");
        if( ob->query("equipped") )
        	return notify_fail("你不可织正穿着的衣物。\n");
        if (ob->query("item_damaged"))
        	return notify_fail("你的衣物破了，得先把它补好才行。\n");
        
                    
	base= (int)ob->query("base_armor");
	current = (int) ob->query("armor_prop/armor");
        
        if (base>50 && !me->query("ji_item/雪蚕丝"))
        	return notify_fail(CYN"老板娘说：“这件"+ob->name()+CYN"需要雪蚕丝才能进一步加固。”\n"NOR);
        if (base>80 && !me->query("ji_item/乌蚕丝"))
        	return notify_fail(CYN"老板娘说：“这件"+ob->name()+CYN"需要乌蚕丝才能进一步加固。”\n"NOR);
        if (base>120 && !me->query("ji_item/天蚕丝"))
        	return notify_fail(CYN"老板娘说：“这件"+ob->name()+CYN"需要天蚕丝才能进一步加固。”\n"NOR);
        
        if(!ob->query("ji_times")) {
		j = 1;
	} else {
		j = ob->query("ji_times");
	}
	if (j>=15) 
		return notify_fail("老板娘摇了摇头说：“凭我的能力，已经无法再加工这件衣物了！”\n");
		
       	for(i=1; i<=j;i++)
		cost = cost * 2;
		tell_object(me, HIY"加工衣物将会使用"+chinese_number(cost)+"两黄金，是否要继续？(continue yes/no)\n"NOR);
        
        me->set_temp("process_zhi",ob);
        add_action("do_continue","continue");
        return 1;
}


int do_continue(string arg) {
	int i, j, cost = 1;
	object me = this_player();
	object ji_person;
	
	int gold = me->query("deposit")/10000;
	
	if (environment(me)!= environment(this_object())
		|| !me->query_temp("process_zhi")
		|| !objectp(me->query_temp("process_zhi"))
		)
		return notify_fail("什么？？\n");
	
	
	if ( arg != "yes" ) { 
		write ("老板娘笑容可掬地说：欢迎下次再来！\n");
		me->delete_temp("process_zhi");
		remove_action("do_continue","continue");
		return 1; 
	}
	
	if( !objectp(ob = me->query_temp("process_zhi")) )
        	return notify_fail("你身上没有这样东西。\n");
        if( !ob->query("armor_prop") )
        	return notify_fail("你只能织能穿在身上的东西。\n");
        if( ob->query("equipped") )
        	return notify_fail("你不可织正穿着的衣物。\n");
        if (ob->query("item_damaged"))
        	return notify_fail("你的衣物破了，得先把它补好才行。\n");
        	
        me->delete_temp("process_zhi");		
	if(!ob->query("ji_times")) {
		j = 1;
	} else {
		j = ob->query("ji_times");
	}
	if (j>=15) 
		return notify_fail("老板娘摇了摇头说：“凭我的能力，已经无法再加工这件衣物了！”\n");
		
	if (me->query_encumbrance()+j*50 > me->query_max_encumbrance())
		return notify_fail("这件衣服再加固下去恐怕你穿不动了。\n");
		
	for(i=1; i<=j;i++)
		cost = cost * 2;	

        if( gold < cost)
		{ 
	        	environment()->delete("processing");
	        	return	notify_fail("你银行里存款不够" + sprintf("%d",cost)+ "两金子。\n");
	       }
        
        me->add("deposit", -cost*10000);
        me->start_busy(1);
	me->save();
	seteuid(ROOT_UID);
	ob->unequip();
	ob->add("armor_prop/armor",j);
	ob->add("base_armor",j);
	ob->set("weight",(int)ob->query("weight")+j*50);
	ob->add("ji_times",1);
	ob->save();
	ob->restore();
	message_vision(CYN"$N拿起针线，把"+ob->name()+CYN"摊在桌上，飞快地织了起来。
一盏茶的功夫，老板娘抖了抖"+ob->name()+CYN"，说道：好了！\n"NOR,this_object());
	seteuid(getuid());
	remove_action("do_continue","continue");
	return 1;
}



int do_xiu(string arg){
	object gold, armor, me, reference;
	int dam, i, total;
	me = this_player();
	
	if(!arg) {
		return notify_fail("你要补什麽衣物？\n");
	}
	
	armor = present(arg, me);
	if(!objectp(armor)) {
		return notify_fail("你要修什么？\n");
	}
	
	if(!armor->query("armor_prop")){
		return notify_fail("老板娘说：我只会补衣物，其他的可不成。\n");
	}
	if(!armor->query("owner")) {
		seteuid(getuid());
		reference = new(base_name(armor));
		if (!reference) {
			message_vision("$N看了看$n手中的" + armor->name() + "说道：这个不值得一补。\n", 
				this_object(), me);
			return 1;
		}
		dam = reference->query("armor_prop/armor") - armor->query("armor_prop/armor");
		destruct(reference);
		
	} else {
	//	Self_made armor fix.	
		dam = armor->query("base_armor") - armor->query("armor_prop/armor");
    }
        
	if(dam <= 0) {
		return notify_fail("你的衣物没有损坏。\n");
	} 
	
	i = dam;
	
	total = MONEY_D->affordable(me,i*10000,1);	// Not allow credit card here
		
	if (!total)
		return notify_fail("你身上没有足够的金子，需要金子" + chinese_number(i) + "两。\n");
	
	MONEY_D->pay_him(me,total-i*10000);
	
	if(armor->query("equipped") == "worn") {
		armor->unequip();
	}
	armor->add("armor_prop/armor", dam);
	armor->set("item_damaged",0);
	message_vision(CYN"$N接过$n手中的" + armor->name() + CYN"左看右看，放在桌上补了起来。\n"NOR, 
			this_object(), me);
 	message_vision(CYN"“好了！”$N咬断丝线，又抖了抖，递还" + armor->name() + CYN"给$n。\n"NOR,
 			this_object(), me);
 	tell_object(me,"修理武器共用去黄金"+chinese_number(i)+"两。\n");
 	if (armor->query("orig_name"))
		armor->set("name",armor->query("orig_name"));
	if (armor->query("owner")) 
		armor->save();
	
	return 1;
}


int	accept_object(object who, object what) {
	
	string item_name;
	item_name= what->query("name");
	
	if (item_name=="雪蚕丝"|| item_name=="天蚕丝"|| item_name=="乌蚕丝"){
		who->set("ji_item/"+item_name,1);
		message_vision(CYN"老板娘拿起"+item_name+CYN"高兴地说，这是稀世之宝，我会替你好好保存到加工护具的时候。\n"NOR,who);
		return 1;
	}
	return 0;
}
		
	