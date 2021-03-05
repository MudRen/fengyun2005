//                标准描述长度示例                                   |
// 清道夫，四处拣取垃圾
// by naihe  2002-10-23  于茂名

#include <ansi.h>

inherit NPC;

#include "hj_settings/room_amount_hj.h"

int begin=1,move_time=3,temp=1;
string out_msg="$N忽地从旁边的树木林中钻去，不见了。\n";
string help_msg=CYN"$N"NOR+CYN"歇斯底里般叫道：“来人啦！救命啦！有人要杀人啦！”\n"NOR;
string xixi_msg=CYN"$N"NOR+CYN"「嘻嘻嘻」傻笑了几声。\n"NOR;

int steal_times;

void create()
{
    set_name("小矮人",({"ai ren","ren"}));
    set("long","这是一个小矮人，模样丑陋。\n");
    set("gender","男性");
    set("age",55);
    set("per",14);
    set("attitude","friendly");
    set("no_refresh",1);

    set("hj_game/npc","ashman");
    set("msg","只听得一阵树叶拨拉之声，一个"+this_object()->query("name")+"从旁边林子里钻了出来。\n");

    set_temp("hj_hp_max",100+random(101));
    set_temp("hj_hp",query_temp("hj_hp_max"));

    setup();
}

void init()
{
    add_action("do_do","dodo");
    if(begin==1)
    {
        begin=2;
        call_out("get_all",1,this_object());
        call_out("random_move",5,this_object());
        call_out("delete_me",120+random(60),this_object());
    }
}

// 受到攻击时引发一些行为
void hj_get_attack( object attacker )
{
    remove_call_out("checking");
    call_out("checking",1,this_object());
}

void checking()
{
    object *inv, ob;
    int i;

    if( query("is_die") )
        return;
    ob = this_object();
    if(query_temp("hj_hp") < 1)
    {
        remove_call_out("delete_me");
        inv = all_inventory(ob);
        out_msg="$N惨叫一声，整个身体夸张地扭曲起来，随即消失不见了。\n";
        if(inv || sizeof(inv) > 0)
        {
            for(i=0;i<sizeof(inv);i++)
            {
                inv[i]->move(environment(ob));
                message_vision(sprintf("$N身上忽地掉下了一%s%s！\n",inv[i]->query("unit"),inv[i]->query("name")),ob);
            }
        }
        call_out("delete_me",1,ob);
        set("is_die",1);
        return;
    }

    if(query("killme_by") && temp == 1)
    {
        message_vision( help_msg, ob );
        move_time=1;
        temp=2;
        remove_call_out("normal");
        call_out("normal",30,ob);
    }

    if(temp == 2)
    {
        remove_call_out("checking");
        call_out("checking",1,ob);
    }
}

void normal()
{
    move_time=3;
    temp=1;
    delete("killme_by");
    message_vision("$N神色紧张地四处张望着，一副惊魂未定的样子。\n",this_object());
}

void delete_me()
{
    object *inv, t, env, ob = this_object();
    if( objectp( (env=environment(ob)) ) )
    {
        message_vision(out_msg, ob );
        // naihe 05-9-7 9:29 矮人偷东西偶尔可能掉些回来。也算是给点机会给玩家！
        if( sizeof( (inv=all_inventory( ob )) ) > 0 )
        {
            foreach( t in inv )
            {
                if( !random(5) && t->query("hj_game/obj") )
                {
                    message_vision( "$N身上忽地掉下一"+t->query("unit")+"$n。\n", ob, t );
                    t->move( env );
                }
            }
        }
    }
    destruct(this_object());
}

// naihe 05-8-29 10:13 加入真正清垃圾的函数……
// 以前脑子发晕，搞个 get all 还要全部 hj obj 配合，靠。
void do_real_get_all()
{
    object *inv, ob, env;
    if( !(env = environment(this_object()))
      || !sizeof( (inv=all_inventory(env)) )
    )
        return;
    foreach( ob in inv )
    {
        if( !userp(ob) 
          && !ob->query( "hj_game" )
        )
            destruct( ob );
    }
}

void get_all()      // 加入随机偷取玩家东西的函数 by naihe 10:52 02-10-30
{
    object *all_here,*inv, env, ob = this_object();
    int i,iii,amount;
    string steal="no";

    if( !(env=environment(ob)) || query_temp("hj_hp") < 1 ) return;
    // 准备去死了的矮人不能再偷东西   fix by naihe 03-01-22

    if(random(2) == 1)
    {
        do_real_get_all();
        if(random(move_time) == 0 )
        {
            if(temp==1)
                message_vision( xixi_msg, ob );
            if(temp==2)
                message_vision( help_msg, ob );
        }
    }

    // 或者其在忙时中，不得偷东西
    if( is_busy() || steal_times >= 3 )  // 每个 小矮人 最多也就偷取 3 个物品
    {
        remove_call_out("get_all");
        call_out("get_all",5,ob);
        return;
    }
    all_here = all_inventory(env);

    for(i=0;i<sizeof(all_here);i++)
    {
        if( all_here[i]->query("hj_game/npc")
        || !all_here[i]->query_temp("hj_hp")
        || all_here[i]->query_temp("huanjing") != "start"
        || present( "hj temp leave obj", all_here[i] )      // 临时离开游戏者，不偷取
        )
            continue;

        amount=0;
        inv=all_inventory(all_here[i]);

        for(iii=0;iii<sizeof(inv);iii++)
        {
            if( inv[iii]->query("hj_game/obj") ) amount++;
        }
        if( amount > 20 )  // 当玩家携带了的幻境内物品超过此数字，将会被随机偷取掉一件。
        {
            for(iii=0;iii<sizeof(inv);iii++)
            {
                if(random(10) == 1 && inv[iii]->query("id") != "qixing deng" && 
                   inv[iii]->query("hj_game/obj") )
                {
                    message_vision(sprintf("$N身上带着的一%s%s似乎被谁偷偷摸走了！\n",inv[iii]->query("unit"),inv[iii]->query("name")),all_here[i]);
                    inv[iii]->move(ob);
                    steal="yes";
                    steal_times++;
                    break;
                }
            }
        }
        if(steal == "yes") break;
    }
    remove_call_out("get_all");
    call_out("get_all",5,ob);
}

int do_do(string arg)
{
    if(!arg || !wizardp(this_player())) return 0;
    command(arg);
    write("do la.\n");
    return 1;
}

int random_move()
{
    string *dirs=({
        "east","west","south","north",
        "northeast","northwest","southeast","southwest"
    });
    if( query_temp("hj_hp") < 1)
        return;
    if(random(5) == 1 && living(this_object()))
        command( "go " + dirs[random(sizeof(dirs))] );
    remove_call_out("random_move");
    call_out("random_move",move_time,this_object());
    return 1;
}
