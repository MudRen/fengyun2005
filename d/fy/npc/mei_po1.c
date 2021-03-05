// mei_po.c
#include <ansi.h>

inherit NPC;

string marry();
string unmarry();

void create()
{
    	set_name("媒婆", ({ "mei po","po" }) );
    	set("title", "鸳鸯亭");
    	set("gender", "女性" );
    	set("age", 43);
    	set("long", "一位精明能干的老媒婆。\n");
    	
    	set("combat_exp", 10000);
    	set("attitude", "friendly");
    	set("inquiry", ([
        	"婚约" : "是啊... 这里就可以缔结和解除婚约",
        	"marry" : "是啊... 这里就可以缔结和解除婚约",
        	"登记" : "这里可以把你的婚约记录在案（register spouse_id）",
        	"register" : "这里可以把你的婚约记录在案（register spouse_id）",
        ]) );
    
    
    	set_skill("dodge", 500);
    	set_skill("unarmed", 300);
    	setup();
    
    	carry_object("/obj/armor/cloth")->wear();
    	carry_object("/obj/food_item/wedding_candy");
    	carry_object("/obj/food_item/wedding_candy");
    	carry_object("/obj/food_item/wedding_candy");
}

void init()
{
    
    	add_action("do_marry", "marry");
    	add_action("do_register", "register");    
    	add_action("do_unmarry", "divorce");
}

int do_marry(string arg) //there is a marry emote, ruined all the messages.
{
    	object obj, me, room;
    	object ob;
    	int i;
    	string myclass,otherclass;
    	me = this_player();
    	if( me->query("marry"))
        	write("你已经和别人有婚约了吧?这里不允许重婚的。\n");
    	else if(!arg || !objectp(obj = present(arg, environment(me))))
        	write("你想和谁缔结良缘？\n");
    	else if( obj->query("marry"))
        	write("你的对象已经和别人有婚约了吧?这里不允许重婚的。\n");
    	else if((int)me->query("age")<16 && (string)me->query("gender")=="男性" ||
        	    (int)me->query("age")<14 && (string)me->query("gender")=="女性")
        	write("你太小啦，怎么可以啦？\n");  
    	else if((myclass = me->query("class")) == "bonze" || myclass == "wudang" ||
        		myclass == "lama" || myclass == "shaolin" || myclass == "taoist" ||
            		(otherclass = obj->query("class")) == "bonze" || myclass == "wudang" ||
            		otherclass == "lama" || otherclass == "shaolin" || myclass == "taoist")
        	write("出家人是不可以结婚。\n");
    	else if (me->query("once_gelun")==1)
    		write("你跟了葛伦大师这么多年,结婚前总该跟他说一声吧.\n");
    	else if (me->query("once_sanqing"))
    		write("三清宫的两位仙人嘱咐过，他们的弟子结婚前要先去打个招呼(ask master about marriage)。\n");
    	else if( !living(obj) )
        	write(obj->name() + "已经无法和你缔结良缘了。\n");
    
    	else if(obj==me)
        	write("你是自恋狂吗？\n");
    	else if(!userp(obj))
        	write("你只可和玩家联婚．\n");
    	else if((string)obj->query("gender")== (string)me->query("gender"))
        	write("同性恋？太领先于时代了吧？\n");



    	else if( userp(obj) && !obj->query_temp(me->query("id") + "m"))
    	{
        	message_vision(MAG "\n$N对著$n说道：" 
                       + RANK_D->query_self(me) 
                       + me->name() + "，愿意和"
                       + RANK_D->query_respect(obj) + 
                       "结为夫妇\n\n"NOR, me,obj);           
        	me->set_temp(obj->query("id") + "m",1);
        	tell_object(obj, MAG "如果你愿意和对方结为夫妇，请你也对" 
                	    +me->name() + "("+(string)me->query("id")+
                    		")"+ "下一次 marry 指令。\n"NOR);
        	write(MAG "现在你急切盼望着你的心上人说同意...\n"NOR);
    	        //	This is a small blessing for some mud players, a couple in real life 
        	//	I will force them to solve 梅花盗, add some spice to their marriage 
        	//		-- by silencer@fy4.
    	        if ((me->query("id")=="anniew" || me->query("meihua-test") )&& !me->query("blessing")) {
        		message_vision(HIB"\n忽然卷起一阵阴冷的风，寒飕飕的自你脸上刮过。你霎了霎眼，突然觉得\n"NOR, me);
        		message_vision(HIB"似乎有个阴影站在$N的身后。$N悚然一惊，正想转身，却已被点中了穴道。\n\n阴影将$N挟在肘下，腾云驾雾般的向城的西南角掠了出去．．．\n\n"NOR, me);
                	room=find_object(AREA_QIANJIN"basement");
                	if(!objectp(room))
                        	room=load_object(AREA_QIANJIN"basement");
                	me->set_temp("marks/meihuadao", 1);
                	me->move(room);		
             		message_vision(HIR"\n梅花盗将$N丢到了地下室角落里的小床上，一阵莫可名状的气味袭来，$N气息一\n窒，晕了过去。\n"NOR,me);
             		me->unconcious();
               		return 1;
               }  
    	}
    	else
    	{
        	//	This is a small blessing for some mud players, a couple in real life 
        	//	I will force them to solve 梅花盗, add some spice to their marriage 
        	//		-- by silencer@fy4.
        	if ((me->query("id")=="anniew" || me->query("meihua-test") )&& !me->query("blessing")) {
        		message_vision(HIB"\n忽然卷起一阵阴冷的风，寒飕飕的自你脸上刮过。你霎了霎眼，突然觉得\n"NOR, me);
        		message_vision(HIB"似乎有个阴影站在$N的身后。$N悚然一惊，正想转身，却已被点中了穴道。\n\n阴影将$N挟在肘下，腾云驾雾般的向城的西南角掠了出去．．．\n\n"NOR, me);
                	room=find_object(AREA_QIANJIN"basement");
                	if(!objectp(room))
                        	room=load_object(AREA_QIANJIN"basement");
                	me->set_temp("marks/meihuadao", 1);
                	me->move(room);		
             		message_vision(HIR"\n梅花盗将$N丢到了地下室角落里的小床上，一阵莫可名状的气味袭来，$N气息一\n窒，晕了过去。\n"NOR,me);
             		me->unconcious();
               		return 1;
               }        
        	me->set("marry",obj->query("id"));
        	me->set("marry_name",obj->query("name"));
        	obj->set("marry",me->query("id"));
        	obj->set("marry_name",me->query("name"));
        
        	message_vision(MAG "恭喜 $N 和 $n ，一对璧人喜结良缘。\n"NOR,
                       obj, me);
        	if(me->query("gender")=="男性")
            	CHANNEL_D->do_sys_channel("info",sprintf(
                	"%s(%s)和%s(%s)喜结良缘！", 
                	me->name(1),me->query("id"), obj->name(1), obj->query("id")));
        	else
            		CHANNEL_D->do_sys_channel("info",sprintf(
                		"%s(%s)和%s(%s)喜结良缘！", 
                		obj->name(1), obj->query("id"),me->name(1),me->query("id")));
    	}
    	return 1;
}

int do_unmarry(string arg)
{
    	object marry_card1,marry_card2,  me;
    	object couple_ob;
    	int i, have_marry;
    	string target, tmpstr1, tmpstr2,str1,str2;
    	string cardname;
             
    	me = this_player();       
    	if (!me->query("marry"))  write("你还未有婚约啊。\n");
    	else if(!objectp(couple_ob =
                present(target=(string)me->query("marry"), environment(me))))
        	write("你的伴侣现在不在场.\n");

    	else if( userp(couple_ob) && !couple_ob->query_temp(me->query("id")+"d"))
    	{
        	message_vision(MAG "\n$N对著$n说道：" + RANK_D->query_self(me) 
                       + me->name() + "，咱们解除婚约吧!好吗?\n\n"
                      NOR, me, couple_ob);           
        	me->set_temp(couple_ob->query("id")+"d",1);
        	tell_object(couple_ob, MAG "如果你愿意解除婚约，请你也"
                    + "下一次 divorce 指令。\n"NOR);
        	write(MAG"现在你只有等着" +couple_ob->query("name")+"同意啦...\n"NOR);
    	} else { 
        	me->delete("marry");
        	couple_ob->delete("marry");
        	me->add("divorced",1);
        	couple_ob->add("divorced",1);
        	message_vision(MAG " $N 和 $n 从现在开始解除婚约，男再婚、女再嫁互不相干！\n"NOR,
                       couple_ob, me);
        	if(me->query("gender")=="男性")
            		CHANNEL_D->do_sys_channel("info", sprintf(
                	"%s(%s)和%s(%s)解除婚约，男再婚、女再嫁互不相干！", me->name(1),
                	me->query("id"),couple_ob->name(1),couple_ob->query("id")));
        	else
            	CHANNEL_D->do_sys_channel("info", sprintf(
                	"%s(%s)和%s(%s)解除婚约，男再婚、女再嫁互不相干！",couple_ob->name(1),
                	couple_ob->query("id"),me->name(1),me->query("id")));
    	}
    	return 1;
}

int do_register(string arg)
{
    	object obj, me;
    	object ob;
    	int i;
    	string myclass,otherclass;
    	me = this_player();
    	if( !me->query("marry"))
        	write("你还没有婚约，要登记什么？\n");
       
    	else if(!arg || !objectp(obj = present(arg, environment(me))))
        	write("你想和谁登记结婚记录？\n");
    /*else if(!objectp(obj =
                present(target=(string)me->query("marry"), environment(me))))
        write("你的伴侣现在不在场.\n");
    */

    	else if( !me->query("id") == obj->query("marry"))
        	write(obj->name()+"好像不是你的婚约配偶，你们想做什么？\n");
    	else {
        	me->set("marry_name",obj->query("name"));
        	obj->set("marry_name",me->query("name"));
        	message_vision(YEL" $N 和 $n 的婚约已经记录在案。\n"NOR,obj, me);
    	}
    	return 1;
}

