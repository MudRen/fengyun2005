// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

#include <ansi.h>
inherit NPC;
inherit F_LEVEL;
object ob;

void create()
{
        set_name("樊夫人", ({ "fan furen","fan","furen" }) );
        set("gender", "男性" );
        set("title", HIR "祭剑师"NOR);
        set("age", 52);
        set("long","樊夫人本是三清宫的一个老道士，人到老年无所事事，
在这里给人祭剑。\n");

        set("inquiry",([
                "藏渊冥器" :"藏渊冥器原本是地府法器，据说在百余年前落入人间，所在之处必聚阴霾。\n",
                "幽冥紫晶" :"幽冥紫晶是稀世之宝，据说只有聪慧绝顶之人才能得到！\n",
                "聪慧绝顶":	"如果你能让那个江湖骗子输的心服口服，那还差不离。\n",
              ]) );

        set("combat_exp", 50000);
        set("str",30);
        set("attitude", "friendly");
        set("busy", 0);
        setup();
        carry_object("/obj/armor/cloth")->wear();
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 2, ob);
        }
        add_action("do_ji","ji");
}


void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        if (present("hell sword", ob) && REWARD_D->riddle_check(ob,"幽冥紫晶")==1) 
        {
			message_vision(CYN"
樊夫人眼中透出热切的光，看着幽冥紫灵剑，喃喃地说：这可是用千古难求的幽冥紫晶
炼成的啊，可惜冶剑之人不得其法，空误了地府之珍。只要能找到藏渊冥器，再以百金
赠我，我就可以重冶此剑，还为幽冥紫晶。\n"NOR, this_object()); 
        } else {
            switch( random(10) ) {
                    case 0:
                            say( "樊夫人笑道：这位" + RANK_D->query_respect(ob)
                                    + "，你的宝刃看起来好象要血祭一下了。\n");
                            break;
                    case 1:
                            say( "樊夫人说道：这位" + RANK_D->query_respect(ob)
                                    + "，你的宝刃杀气不足，来血祭一下宝刃吧。\n");
                            break;
                    case 2: message_vision("樊夫人自言自语地说：那传世之珍幽冥紫晶，也不知道流落到了哪里。\n",ob);
                    		break;
            }
        }
}


int accept_object(object who, object ob) {
        object sword;
        string item_name, ob_name;
        string *material_names=({ "幽冥紫灵剑",MAG"藏渊冥器"NOR });
        int success, makeup_ok, i;
        if (query("busy"))
        	return notify_fail("樊夫人现在正忙。\n");
        	
        item_name= ob->query("real");
        if (item_name=="狗尾巴草"|| item_name=="成形首乌"|| item_name=="千年老参"){
                who->set("ji_item/"+item_name,1);
                message_vision(CYN"樊夫人拿起"+item_name+CYN"看了半晌，喜形于色。\n樊夫人抚着下巴上稀稀拉拉的几根胡子，嘿嘿笑道：不错，不错。\n"NOR,who);
                return 1;
        }

		if (ob->query("money_id") == "gold") {
     		if (REWARD_D->riddle_check(who,"幽冥紫晶")!=2) {
     			command("shake");
     			command("say 先等你把幽冥紫灵剑和藏渊冥器都找给我再说吧。");
     			return 0;
     		}
            if (ob->query_amount() < 100 ) {
                command("shake");
                command("say 这可是件大事儿，没百两足金拿不下来！");
                return 0;
            }            
            
            message_vision("\n$N从$n拿出幽冥紫灵剑，放入冶剑炉中。\n", this_object(), who); 
            message_vision(HIC"炉火渐渐从红色转成青白之色，樊夫人掏出藏渊冥器投了进去。
哧的一声，炉火又窜起一尺多高。。。。。。\n"NOR, this_object());
            set("busy", 1);
            call_out("ext_stone", 3, who);
            who->perform_busy(2);
            return 1;
		}
		
		ob_name=ob->query("name");
		
		if (REWARD_D->riddle_check(who,"幽冥紫晶")!=1) {
			if (ob_name ==MAG"藏渊冥器"NOR)
				command("say 你还是先去找到幽冥紫灵剑吧。");
				return 0;
		}			
		
		success=1;
		makeup_ok=0;
		for(i=0;i<2;i++)
		{
			if(ob_name==material_names[i])
			{
				if(who->query("marks/wangfuren/"+ob_name))
				{
					command("say 这原料你已经给过我了！”\n");
					return 0;
				}
				if (ob_name==MAG"藏渊冥器"NOR && !who->query("annie/亘古魂幡"))
				{
					ccommand("say 藏渊冥器唯有自己亲手得到的才有灵气啊。");
					return 0;
				}
				who->set("marks/wangfuren/"+ob_name,1);
				command("say 好，此物我且收下。");
				makeup_ok=1;
			}
			success = success*who->query("marks/wangfuren/"+material_names[i]);
		}
		if(!success) return makeup_ok; 

		command("say 好，原料都已经齐了，只要有足够的资金，我就能够将幽冥紫晶提取出来。");
		REWARD_D->riddle_set(who,"幽冥紫晶",2);
		return 1;				

        
}

//	You can keep the stone, but if you lose it, you still have the mark
//	YOu can either ask other to get the stone, or do it youself again.
int ext_stone(object me){
        object stone;
        set("busy", 0);
        if (!me)	return 1;
        if (environment(me) == environment(this_object())) {
            message_vision(MAG"\n忽然间，紫光闪耀，映彻天地。\n"NOR, this_object()); 
            message_vision(HIR"$N忽然用刀在自己的手臂上一划，一股血箭射入冶剑炉。\n"NOR, this_object()); 
            message_vision(MAG"\n紫光大盛之下，你不由得闭上眼睛。\n"NOR, this_object());
            message_vision("睁眼看时，樊夫人已将一块幽光闪闪的紫石托在手中。\n", this_object()); 
            
            stone = new("/obj/specials/stone/pstone");
            if (stone->move(me)) {
            	message_vision("$N递给$n一块紫石。\n", this_object(), me);
            	REWARD_D->riddle_done(me,"幽冥紫晶",200,1);
	        	if(!me->query("stone_mark/pstone")){
	            	me->set("stone_mark/pstone",1);
	            }
	            log_file("riddle/IMBUE_LOG",
                  sprintf("%s(%s) 提练幽冥紫晶成功。 %s \n",
                        me->name(1), geteuid(me), ctime(time()) ));
        	}else
        		stone->move(this_object());
        } 
        return 1;
}

object get_material(object me)
{
	object *inv;
	int i;
	inv=all_inventory(me);
	for (i=0;i<sizeof(inv); i++)
		if (inv[i]->query("weapon_material"))
			return inv[i];
	return 0;
}

int  do_ji(string arg)
{
        object me,obx;
        
        int gold;
        int cost =1;
        int i,j,base,current;
        string id,name,broken;  
        string file,newfile,filestring;
        me = this_player();
        id = me->query("id");
        if( !arg ) return notify_fail("你要祭什麽武器？\n");

		if (me->query("created_item")>1)
			return notify_fail("樊夫人摇头道：风云只能有一件自制武器，请将多余的用destroy命令销毁。\n");
		
		
		obx=get_material(me);
		if (!obx)
			return notify_fail("樊夫人摇头道：祭武器那可得有好材料才行。\n");

		if (me->query("ji/"+obx->query("material_level")))
			return notify_fail("樊夫人摇头道：你已经用"+obx->name()+"祭过了。\n");

//      gold = present("gold_money", this_player());
//      if( !gold) return notify_fail("你身上没有金子。\n");

        if( !objectp(ob = present(arg, me)) )
                return notify_fail("你身上没有这样东西。\n");
        if(me->is_busy())
                return notify_fail("你上一个动作还没有完成。\n");
        if( !ob->query("weapon_prop") )
                return notify_fail("你只能祭可当作武器的东西。\n");
        if( ob->query("equipped") )
                return notify_fail("你不可祭装备著了的武器。\n");
        if( !ob->query("owner") )
                return notify_fail("你只可祭自己打造的武器。\n");
        
        sscanf(ob->query("name"),"%s的",broken);
        if(broken=="断掉")
                return notify_fail("你不可祭损坏了的武器，请去张铁匠那里修好武器再来祭。\n");
        
        base= (int)ob->query("base_damage");
        current = (int) ob->query("weapon_prop/damage");
        if (base != current)
                return notify_fail("你不可祭损坏了的武器，请去张铁匠那里修好武器再来祭。\n");

/*
        if(!ob->query("ji_times")) {
                j = 1;
        } else {
                j = ob->query("ji_times");
        }

        if (j>=15) 
                return notify_fail("樊夫人摇了摇头说：“凭我的能力，已经无法再祭这把武器了！”\n");
        else if (j >= 12 && !me->query("ji_item/狗尾巴草"))
                return notify_fail("樊夫人摇摇头道：老道士最近失血太多，不想煅剑，除非……除非……\n樊夫人突然眯起眼，嘿嘿笑道：除非你找支狗尾巴草来给老道士补一补。\n\n");
        else if (j >= 10 && !me->query("ji_item/成形首乌"))
                return notify_fail("樊夫人摇摇头道：老道士最近失血太多，不想煅剑，除非……除非……\n樊夫人突然眯起眼，嘿嘿笑道：除非你找支成形首乌来给老道士补一补。\n\n");
        else if (j >= 8 && !me->query("ji_item/千年老参"))
                return notify_fail("樊夫人摇摇头道：老道士最近失血太多，不想煅剑，除非……除非……\n樊夫人突然眯起眼，嘿嘿笑道：除非你找支千年老参来给老道士补一补。\n\n");

        for(i=1; i<=j;i++)
                cost = cost * 2;
*/
		cost = 10;
        tell_object(me, HIY"祭武器将会使用"+chinese_number(cost)+"两黄金，是否要继续？(continue yes/no)\n"NOR);
        add_action("do_continue","continue");
        me->set_temp("process_ji",ob);
        return 1;
}

int do_continue(string arg) {
        int i, j, cost = 1;
        object me = this_player();
        object ji_person,obx;
        string broken;
        int gold, base, current;
                
        if (environment(me)!= environment(this_object())
                || !me->query_temp("process_ji")
                || !objectp(me->query_temp("process_ji"))
                )
                return notify_fail("什么？\n");
                
                
        if ( arg != "yes" ) { 
                write ("樊夫人笑容可掬地说：欢迎下次再来！\n");
                me->delete_temp("process_ji");
                remove_action("do_continue","continue");
                return 1; 
        }

		obx=get_material(me);
		if (!obx)
			return notify_fail("樊夫人摇头道：祭武器那可得有好材料才行。\n");

		if (me->query("ji/"+obx->query("material_level")))
			return notify_fail("樊夫人摇头道：你已经用"+obx->name()+"祭过了。\n");

		if (exp_to_level(me->query("combat_exp"))["level"]<obx->query("material_level"))
			return notify_fail("樊夫人摇头道：你必须达到"+obx->query("material_level")+"级才能用此物品祭剑。\n");
        
        if( !objectp(ob = me->query_temp("process_ji")) )
                return notify_fail("你身上没有这样东西。\n");
        
        me->delete_temp("process_ji");
        
        if( !ob->query("weapon_prop") )
                return notify_fail("你只能祭可当作武器的东西。\n");
        if( ob->query("equipped") )
                return notify_fail("你不可祭装备著了的武器。\n");
        if( !ob->query("owner") )
                return notify_fail("你只可祭自己打造的武器。\n");
        
        sscanf(ob->query("name"),"%s的",broken);
        if(broken =="断掉")
                return notify_fail("你不可祭损坏了的武器，请去张铁匠那里修好武器再来祭。\n");
        
        base= (int)ob->query("base_damage");
        current = (int) ob->query("weapon_prop/damage");
        if (base != current)
                return notify_fail("你不可祭损坏了的武器，请去张铁匠那里修好武器再来祭。\n");

        if(!ob->query("ji_times")) {
                j = 1;
        } else {
                j = ob->query("ji_times");
        }




        if (j>=15) 
                return notify_fail("樊夫人摇了摇头说：“凭我的能力，已经无法再祭这把武器了！”\n");
/*        
        else if (j >= 12 && !me->query("ji_item/狗尾巴草"))
                return notify_fail("樊夫人摇摇头道：老道士最近失血太多，不想煅剑，除非……除非……\n樊夫人突然眯起眼，嘿嘿笑道：除非你找支狗尾巴草来给老道士补一补。\n\n");
        else if (j >= 10 && !me->query("ji_item/成形首乌"))
                return notify_fail("樊夫人摇摇头道：老道士最近失血太多，不想煅剑，除非……除非……\n樊夫人突然眯起眼，嘿嘿笑道：除非你找支成形首乌来给老道士补一补。\n\n");
        else if (j >= 8 && !me->query("ji_item/千年老参"))
                return notify_fail("樊夫人摇摇头道：老道士最近失血太多，不想煅剑，除非……除非……\n樊夫人突然眯起眼，嘿嘿笑道：除非你找支千年老参来给老道士补一补。\n\n");
*/
        if (me->query_encumbrance()+j*100 > me->query_max_encumbrance())
                return notify_fail("这把武器再祭下去恐怕你拿不动了。\n");
        
		cost = 10;

        gold = me->query("deposit")/10000;
        if( gold < cost)
                return  notify_fail("你银行里存款不够" + sprintf("%d",cost)+ "两金子。\n");
        
        me->start_busy(1);        
        me->add("deposit", -cost*10000);
        me->add("bellicosity",cost);
        
// need to update 3 things: damage, rigidity, and weight, base_damage is to keep track
// damage on weapon so we can xiu weapon later on.
        seteuid(ROOT_UID);

		me->add("ji/"+obx->query("material_level"),1);

        ob->unequip();
        ob->add("weapon_prop/damage",10);
        ob->add("base_damage", 10);
        ob->set("weight",ob->query("weight")+300);
        ob->add("rigidity",50);
        ob->add("ji_times", 1);
        ob->save();
        ob->restore();
        me->save();
        seteuid(getuid());
        
        message_vision("\n$N从$n手中取过"+ob->name()+"和"+obx->name()+"，放入冶剑炉中。\n", this_object(), me); 
        message_vision(HIC"炉火渐渐从红色转成青白之色。\n\n\n"NOR, this_object());
        message_vision(HIR"$N忽然用刀在自己的手臂上一划，一股血箭射入冶剑炉。\n"NOR, this_object()); 
        message_vision(HIC"\n炉火暴涨之下，你不由得闭上眼睛。\n"NOR, this_object());
        message_vision("$N说道：好了！\n\n",this_object());
        message_vision("睁眼看时，樊夫人已将$n交还给$N手中。\n", me, ob); 
                
		destruct(obx);
        remove_action("do_continue","continue");
        return 1;
}

