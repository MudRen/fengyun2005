#include <ansi.h>
inherit ITEM;

#define MAX_ITEM 5

int do_put(object me, object obj, object dest);
int do_get(object me, object ob, object env);   //modified

void create()
{
        set_name("红木大柜", ({ "big mugui"}) );        // 让这个id有别于其他东西。不使用单字id!
        set_weight(300);
        set_max_encumbrance(80000);
        set("unit", "个");
        set("long", "一个用上好红木作的木柜。\n");
        set("no_get",1);
        set("value", 0);
         seteuid(getuid());
}

int is_container() {return 1;}

/*
int reset_item_list(object dest)
{
        object room = environment(),obj,*inv;
        mapping item_list,item;
        mapping list,tlist;
        int i,j;
        inv = all_inventory(dest);
        i = sizeof(inv);
        room->delete("item_list");
        for (j=0;j<i ;j++ )
        {
                obj = inv[j];
                list = (mapping)obj->query_entire_dbase();
                tlist = (mapping)obj->query_entire_temp_dbase();

                        item =
                        ([
                                "item_basename": base_name(obj),
                                "data":list,
                                "temp_data":tlist,
                                "item_name": obj->query("name"),
                                "item_id": obj->parse_command_id_list(),
                                "amount": obj->query_amount(),
                        ]);
                room->set("item_list/"+(j+1),item);
        }
        room->save();
        return 1;
}

void init()
{
        add_action("do_putitem","put");
        add_action("do_getitem","get");
}


int do_getitem(string arg)
{
        object me = this_player(),env=this_object();
        string from, item;
        object obj, *inv,  obj2;
        object *my_inv, my_item;
        int i, j, amount, num;
        string arg1, from1;

        if( !arg ) return notify_fail("你要捡起什麽东西？\n");
        if( me->is_busy() )
                return notify_fail("你上一个动作还没有完成！\n");

// prevent people using get xyz from wall 0 
// prevent people using get xyz from wall 1
        if ( sscanf(arg, "%s from %s %d", arg1, from1, num)==3) {
                if (num==0 || num ==1)
                        return notify_fail("不必或不能使用get xxx from xxx 0/1。\n");
        }

        if( sscanf(arg, "%s from %s", arg, from)!=2 )
                return 0;
                // 丢给正常get指令处理
        if (present(from,environment(me)) != env)
                return 0;

        
        // Check if a certain amount is specified.
        if(sscanf(arg, "%d %s", amount, item)==2) {
                if( !objectp(obj = present(item, env)) )
                        return notify_fail("这里没有这样东西。\n");
                if( !obj->query_amount() )
                        return notify_fail( obj->name() + "不能被分开拿走。\n");
                if( amount < 1 )
                        return notify_fail("东西的个数至少是一个。\n");
                if( amount > obj->query_amount() ) {
                        return notify_fail("这里没有那麽多的" + obj->name() + "。\n");
                } else if(amount == (int)obj->query_amount()) {
                        return do_get(me, obj, env);    //modified
                } else {
                        obj->set_amount( (int)obj->query_amount() - amount );
                        obj2 = new(base_name(obj));
                        obj2->set_amount(amount);
                        obj2->move(me);         //modified
                        // Counting precise amount costs more time.
                        if( me->is_fighting() ) me->start_busy(3);
                        return do_get(me, obj2, env);   //modified
                }
        }

        // Check if we are making a quick get.
        if(arg=="all") {
                if( me->is_fighting() ) 
                        return notify_fail("你还在战斗中！只能一次拿一样。\n");
                if( !env->query_max_encumbrance() )     return notify_fail("那不是容器。\n");

                inv = all_inventory(env);
                if( !sizeof(inv) )
                        return notify_fail("那里面没有任何东西。\n");
                
        //      15 sec corpse loot protection. Only killer/self can loot the corpse.    
                if (env->query("allow_to_loot")) {
                        if (env->query("death_time")+15 > time()) {
                                if ( member_array( me,env->query("allow_to_loot")) == -1
                                        && env->query("victim_name")!= me->query("name"))
                                                return notify_fail("你现在还不能拿起这件东西。\n");
                        }
                }
        
                for(i=0; i<sizeof(inv); i++) {
                        
                        if( (inv[i]->is_character() && !inv[i]->query("yes_carry")) 
                                || inv[i]->query("no_get") || inv[i]->query("lore")) continue;
                        
                        if (inv[i]->query("allow_to_loot")) {
                        if (inv[i]->query("death_time")+15 > time()) {
                                if ( member_array( me,inv[i]->query("allow_to_loot")) == -1
                                        && inv[i]->query("victim_name")!= me->query("name"))
                                                return notify_fail("你现在还不能拿起这件东西。\n");
                                }
                        }
                        do_get(me, inv[i], env);        //modified
                }
                write("Ok。\n");
                return 1;
        }

        if( !objectp(obj = present(arg, env)) || (living(obj) && !(int)obj->query("yes_carry")))
                return notify_fail("你附近没有这样东西。\n");

        if( obj->query("no_get") )
                return notify_fail("这个东西拿不起来。\n");

//      lore item, you can only own one in your inventory at a time
        if ( obj->query("lore")) {
                my_inv = all_inventory(me);
                for(j=0;j<sizeof(my_inv);j++){
                        my_item = my_inv[j];
                        if(obj->query("name")==my_item->query("name")
                                && my_item->query("lore"))
                        return notify_fail("这样东西你最多只能有一件。\n");
                        }
        }

//      15 sec corpse loot protection. Only killer/self can loot the corpse.    
        
        if (env->query("allow_to_loot")) {
                if (env->query("death_time")+15 > time()) {
                        if ( member_array( me,env->query("allow_to_loot")) == -1
                                && env->query("victim_name")!= me->query("name"))
                                return notify_fail("你现在还不能拿起这件东西。\n");
                }
        }
        if (obj->query("allow_to_loot")) {
                if (obj->query("death_time")+15 > time()) {
                        if ( member_array( me,obj->query("allow_to_loot")) == -1
                                && obj->query("victim_name")!= me->query("name"))
                                return notify_fail("你现在还不能拿起这件东西。\n");
                }
        }
        
        return do_get(me, obj, env);    //modified
}


int do_get(object me, object obj,object env)    //modified
{
        object old_env, *enemy;
        int equipped;
        object target;
        string  prep;

        target = me;
        if( !obj ) return 0;
        old_env = env;  //modified
        if( obj->is_character()  && !obj->is_corpse()) {
                return notify_fail("你不能背负活物。\n");
                // If we try to save someone from combat, take the risk :P
        } else {
                if( obj->query("no_get") ) return 0;
        }

        if( obj->query("equipped") ) equipped = 1;
        if( obj->query("yes_carry")) target = environment(me);
        if( obj->move(target) ) {
                if((int)obj->query("no_transfer")){
                        obj->set("no_get",1);
                        obj->set("no_drop",1)
                
                reset_item_list(this_object())
                if(me->is_fighting())
                        me->start_busy(1)
                if( obj->is_character()  && !obj->query("yes_carry")
                        message_vision( "$N将$n扶了起来背在背上。\n", me, obj )
                else 
                        if(old_env==environment(me)) prep =  "捡起"
                        else if(old_env->is_character()) prep =  "从" + old_env->name() + "身上" + (equipped? "除下" : "搜出")
                        else switch( old_env->query("prep") ) 
                                case "on"
                                        prep = "从" + old_env->name() + "上拿起"
                                        break
                                case "under"
                                        prep = "从" + old_env->name() + "下拿出"
                                        break
                                case "behind"
                                        prep = "从" + old_env->name() + "后拿出"
                                        break
                                case "inside"
                                        prep = "从" + old_env->name() + "中拿出"
                                        break
                                default
                                        prep = "从" + old_env->name() + "中拿出"
                                        break
                        }
                        message_vision( sprintf("$N%s一%s$n。\n", prep
                                obj->query("unit")), me, obj )
                
                return 1
        
        else return 0
int do_putitem(string arg
        object me = this_player(),dest=this_object()
        string target, item
        object obj, *inv, obj2
        int i, amount
        if(!arg) return notify_fail("你要将什麽 [2;37;0m0m统】黄山佛光(/d/huangshan/guangming.c)景观现在就要发生了，现在happen是1。

 [2;37;0m生了，现在happen是1。

 [2;37;0m？\n")
        if (present(target,environment(me)) != dest
                return 0
       
        if(sscanf(item, "%d %s", amount, item)==2) 
                if( !objectp(obj = present(item, me)) 
                        return notify_fail("你身上没有这样东西。\n")
                if( !obj->query_amount() 
                        return notify_fail( obj->name() + "不能被分开。\n")
                if( amount < 1 
                        return notify_fail("东西的数量至少是一个。\n")
                if( amount > obj->query_amount() 
                        return notify_fail("你没有那麽多的" + obj->name() + "。\n")
                else if( amount == (int)obj->query_amount() 
                        return do_put(me, obj, dest)
                else 
                                obj2 = new(base_name(obj))
                                obj2->set_amount(amount)
                                if (do_put(me, obj2, dest)
                                
                                        obj->set_amount( (int)obj->query_amount() - amount )
                                        return 1
                                }              
                                if (obj2) destruct(obj2)
                                return 0
                
        
        if(item=="all"
        
                inv = all_inventory(me)
                for(i=0; i<sizeof(inv); i++
                        if( inv[i] != dest  && !inv[i]->query("no_drop"))
                        do_put(me, inv[i], dest)
                write("Ok.\n")
                return 1
        
        if(!objectp(obj = present(item, me))
                return notify_fail("你身上没有这样东西。\n")
        return do_put(me, obj, dest)
int do_put(object me, object obj, object dest
        string prep
        int container_size
       
        if((int) obj->query("no_drop") ||(int) obj->query("no_get")||obj->query("lore")
                return notify_fail("你不可以这么做。\n")
        if (obj->is_container()
                return notify_fail("你不能把容器放在另一个容器里。\n");
        if( obj == dest
                        return notify_fail("你不可以这么做。\n")
       
        if(dest->is_closed()
                return notify_fail("你要先把" + dest->name() + "打开。\n")
        container_size = dest->query("size") ? dest->query("size") : MAX_ITEM
        // 这里有别于普通put指令，因此不能return notify_fail。 annie 08.200
        // <-------------------------------------------------------------
        if(sizeof(all_inventory(dest)) >= container_size
        
                tell_object(me,dest->name() + "里面最多只能放" + chinese_number(container_size) 
                                "件物品。\n")
                return 1
        
        if (obj->query("no_stock")
        
                tell_object(me,"这样东西无法存放。\n")
                return 1
        
        if (obj->query("value") < 4)    // 无法典当的东西被认为是unique item?
        
                tell_object(me,"这样东西并不值多少钱，没有小心保存的必要。\n")
                return 1
        
        // --------------------------------------------------------------
       
        switch((string)dest->query("prep")) 
                case "on" 
                        prep = "放在" + dest->name() + "上"
                        break
                case "under" 
                        prep = "放在" + dest->name() + "下"
                        break
                case "behind" 
                        prep = "放在" + dest->name() + "后面"
                        break
                case "insdie" 
                        prep = "放进" + dest->name() + "里面"
                        break
                default 
                        prep = "放进" + dest->name() + "里面"
                        break
        
        if( obj->move(dest) ) 
                message_vision( sprintf("$N将一%s%s%s。\n"
                        obj->query("unit"), obj->name(), prep)
                        me )
                if(obj->query("no_drop") || obj->query("no_get")|| obj->query("lore")
                        dest->add("no_give",1)
                reset_item_list(dest)
                return 1
        
        else return 0
/
　　　　　　　╔?
　　　　　　　║╰?
　　　　　　　║│╰?
　　　　　　　║││╰?
　　　　　　　║│││?
　　　　　　　╚╧╧╧?
　　　　　　　- FengYun - 　　?
　　　　　　annie 08.200
　　　dancing_faery@hotmail.co
*
chat 我修改了自建屋子
chat 希望它可以工作..
chat 正在uploda
chat 正在upload

update /obj/item/box.c

chat lag .....................
chat* slogan

*/