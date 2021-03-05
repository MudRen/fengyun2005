// 安儿的药草实验田

#include <ansi.h>
inherit __DIR__"annieitem";

void create()
{
        set_name("药草地", ({ "herb field"}) ); // 让这个id有别于其他东西。不使用单字id!
        set_weight(30000);
        set_max_encumbrance(100);
        set("unit", "片");
        set("desc", "一片药草地，据说不用种子，只需水浇，就会长出草药。\n");
        set("no_get",1);
        set("no_sell",1);
        set("no_drop",1);
        set("no_stack",1);
        set("no_reset",1);
        set("item_type","q");
        set("outdoors",1);
        set("size",1);
set("tax",30);
set("score_tax",3);
        set("value", 300000);
        seteuid(getuid());
}

int is_container(){     return 1;}

void init()
{
	::init();
	if (environment() != this_player())
			add_action("do_water","water");
}

int do_putitem(string arg)
{
        object me = this_player(),dest=this_object();
        string target, item;
        object obj, *inv, obj2;
        int i, amount;

        if(!arg) return notify_fail("你要将什麽东西放进哪里？\n");

        if( sscanf(arg, "%s in %s", item, target)!=2 )
                return notify_fail("你要给谁什麽东西？\n");

        if (present(target,environment(me)) != dest)
                return 0;
        
        write("请保持环境清洁，不要将垃圾望药草地里乱丢。\n");
        return 1;
}


int reset_item_list(object dest)
{
	return 1;
}

int do_water(string arg)
{
        int     s, amount, da,req;
        object me = this_player(),env=environment(me),ob=this_object(),skin,herb;
        object * inv;
        string target,what;
        int i,water;

        string *water_type = ({
        "白毫","葡萄美酒","淡绿色的清水","微清的井水","成都蛋汤","山鸡开屏","盐水","漂着一些东西的水","冰水",
        });
        if (!env->is_owner(me->query("id")))
                return notify_fail("屋子里的物件只有主人才能使用。\n");
        if (!arg)
                return 0;
        if (sscanf(arg,"%s in %s",what,target) != 2)
                return 0;
        if (present(target,env) != ob)
                return 0;
        if (!skin =     present(what,me))
                return notify_fail("你要用什么来浇灌？\n");
        if (!skin->query("liquid/type"))
                return notify_fail( skin->name() +"能用来装水吗？>\"<\n");
        if (!skin->query("liquid/remaining"))
                return notify_fail( skin->name() +"是空的。\n");

        inv = all_inventory(ob);
        if (sizeof(inv))
                return notify_fail( "药草地中有些东西，小心冲跑了。\n");

        if (skin->query("liquid/name") == "清池凝露")
        {
                if (!ob->query("used"))
                        return notify_fail( "药草地十分干净，不需要胡乱冲洗。\n");
                if (me->is_fighting() || me->is_busy()) return 1;
                skin->add("liquid/remaining",-2-random(5));
                if (skin->query("liquid/remaining") < 0)
                        skin->set("liquid/remaining",0);
                message_vision(CYN"\n$N小心翼翼的用"+skin->name()+"中的"+skin->query("liquid/name")+"冲洗了一次药草地。\n", me);
                set("used",0);
                return 1;
        }
        else
        {
                if (ob->query("used"))
                        return notify_fail( "在再次使用药草地之前，你需要用清池凝露洗去残余的污渍。\n");
        }


        if (me->is_fighting() || me->is_busy()) return 1;
        me->perform_busy(2);

        skin->add("liquid/remaining",-2-random(5));
        if (skin->query("liquid/remaining") < 0)
                skin->set("liquid/remaining",0);

        message_vision(CYN"\n$N小心翼翼的将"+skin->name()+"中的一些"+skin->query("liquid/name")+"浇灌在药草地上。\n", me);

        if (query("last_irrigated") + 300 > time())
        {
                // 灌太多水....死掉了
                set("herb_type",0);
                set("herb_time",0);
                set("last_irrigated",0);
                set("used",1);  // 需要清洁了
                herb = new("/obj/medicine/herb_failed.c");
                herb->move(ob);
                message_vision(CYN"只听$N一声惊呼，似是水灌得太多，药草已经连根烂掉了。\n", me);
                return 1;
        }

        if (query("last_irrigated")>1 && query("last_irrigated") + 900 < time())
        {
                // 太久没有灌....长出仙人掌了
                set("herb_type",0);
                set("herb_time",0);
                set("last_irrigated",0);
                set("used",1);  // 需要清洁了
                herb = new("/obj/medicine/cactus.c");
                herb->move(ob);
                message_vision(CYN"只听$N一声惊呼，田里似乎长出了什么奇怪的东西．．．\n", me);
                return 1;
        }

        set("last_irrigated",time());
        add("herb_time",1);
        for (i=0; i<sizeof(water_type);i++ )
                if (skin->query("liquid/name") == water_type[i])
                        water=i+1;
        switch (query("herb_time"))
        {
        case 1:
                add("herb_type",water);
                break;
        case 2:
                add("herb_type",water*100);
                break;
        case 3:
                add("herb_type",water*10);
        
                switch (query("herb_type"))
                {
                        case 129:
                                herb = new("/obj/medicine/herb_f2.c");
                                req=9;
                                break;
                        case 247:
                                herb = new("/obj/medicine/herb_f3.c");
                                req=8;
                                break;
                        case 832:
                                herb = new("/obj/medicine/herb_e2.c");
                                req=7;
                                break;
                        case 571:
                                herb = new("/obj/medicine/herb_d12.c");
                                req=6;
                                break;
                        case 768:
                                herb = new("/obj/medicine/herb_d22.c");
                                req=5;
                                break;
                        case 496:
                                herb = new("/obj/medicine/herb_d32.c");
                                req=4;
                                break;
                        case 985:
                                herb = new("/obj/medicine/herb_e1.c");
                                req=3;
                                break;
                        case 613:
                                herb = new("/obj/medicine/herb_c1.c");
                                req=2;
                                break;
                        case 354:
                                herb = new("/obj/medicine/herb_c2.c");
                                req=1;
                                break;
                        default:
                                herb = new("/obj/medicine/mushroom.c");
                                req=0;
                                break;
                }
//                if (me->query("marks/herb_knowledge") < req)
				if (me->query_skill("herb",1) < req*20+20)
                        herb = new("/obj/medicine/mushroom.c");

                herb->set_amount(1);
				herb->set("value",0);
				herb->set("base_value",0);
                set("herb_type",0);
                set("herb_time",0);
                set("last_irrigated",0);
                set("used",1);  // 需要清洁了
                herb->move(ob);
                message_vision(CYN"\n在$N的精心照料下，田里长出了一些"+herb->name()+"．．．\n", me);
                break;
        }
        return 1;
}

/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/

