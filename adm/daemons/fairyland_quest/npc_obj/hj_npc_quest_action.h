// for hj_npc_quest.c  #include.
// naihe 16:30 03-10-19
// naihe 05-9-12 8:15 hj2003 继续更新~~
#include <set_del_color.h>
void delete_me()
{
    int q_iii = query("iii"), award_score;
    object temp_obj,ob=this_object();

    if( q_iii == 0 || q_iii == 4 )
        message_vision("$N四下看了看，匆匆离开了。\n",ob);
    if( q_iii == 1 )
    {
        if(query("go_where") !="ok")
        {
            if(!query("following_name"))
                message_vision("$N满脸迷茫地走了开去……又多了一个迷失儿童……\n",ob);
            else
            {
                message_vision("$N大声哭道：“"+query("following_name")+"你又说带我去，那么久了都没去到！”\n",ob);
                message_vision("只见$N伤心地往旁边的路上走去……又多了一个迷失儿童……\n",ob);
                temp_obj=find_player(query("following_id"));
                if(temp_obj && temp_obj->query_temp("huanjing") == "start" &&
                   temp_obj->query_temp("hj_score") > 200 )
                {
                    award_score = 30 + random(21);
                    temp_obj->add_temp("hj_score",-award_score );
                    tell_object(temp_obj,"过了许久，你才想起来你曾答应过带一个迷路的小精灵找什么地方的！\n你觉得心里掠过一丝内疚。\n"HIR"游戏提示：你的得分减少了 "+award_score+" 点。\n"NOR);
                }
            }
        }
        else
        {
            message_vision("$N高兴极了，甜甜地说道：“谢谢你，"+query("following_name")+"！”\n",ob);
            message_vision("$N挥了挥手，走了开去。\n",ob);
        }
    }
    if( q_iii == 2)
        message_vision("只见$N一拍脑袋，说道：“哎呀，忘记了家里的小鱼还没喂！”\n$N急急忙忙地离开了。\n",ob);
    if( q_iii == 3)
    {
        if(!query("asking") )
            message_vision("$N轻叹一声，说道：“罢了，罢了！”，竟尔就此离去。\n",ob);
        else
        {
            if(query("asking") == "ok")
            {
                message_vision("只见$N自言自语道：“想不到除了老头子我，还有人对武林人士都那么熟悉！”\n",ob);
                message_vision("$N一边说着，一边踱步前行，就此离去了。\n",ob);
            }
            if(query("asking") == "fail")
            {
                message_vision("$N摇头叹道：“难道就再没有人，能够把这武林之人事熟知于心？”说罢，竟尔就此离去。\n",ob);
            }
            if(query("asking") == "waiting" && query("asking_for_id") )
            {
                temp_obj = present(query("asking_for_id"),environment(ob));
                if(temp_obj)
                {
                    message_vision("$N长叹一声，说道：“"+query("asking_for_name")
                        +"，你仍未想得到吗？这人是"+query("the_answer")+"！”\n",ob);
                    message_vision("$N十分失望地说道：“这人如此有名，你竟然不知道！你仔细想想吧！”\n",ob);
                    message_vision("$N惭愧之色立现于脸，顿时陷入了沉思中。\n",temp_obj);
                    temp_obj->start_busy(20);
                    message_vision("只见$N一边摇着头，一边离开了。\n",ob);
                }
                else
                {
                    temp_obj=find_player(query("asking_for_id"));
                    if( temp_obj && temp_obj->query_temp("huanjing") =="start" )
                    {
                        ob->move(environment(temp_obj));
                        message_vision("只见一个老人走了过来，对着$N劈头就骂道："
                            +"“哪有如你如此无理之人？答应回答我的问题，却悄悄溜走！”\n",temp_obj);
                        message_vision("老人忽地一掌向$N击来！$N躲闪不得，一阵麻木"
                            +"随之而来，顿时动弹不得！\n",temp_obj);
                        temp_obj->start_busy(30);
                        message_vision("$N说道：“你给我好好反省反省罢！”言罢竟然就此离去！\n",ob);
                    }
                }
            }
        }
    }
    if( q_iii == 5 || q_iii == 6 )
    {
        if( query("all_found") )
            message_vision("$N一脸喜悦之情，往旁边走了开去。\n", ob);
        else
            message_vision("$N长叹一声，往旁边走了开去。\n", ob);
    }
    destruct(ob);
}

void init()
{
    switch( query("iii") )
    {
        case 0: case 4:
            add_action("do_gmai",({ "gmai", "gbuy" }) );
            add_action("do_glist","glist");
            break;
        case 1: case 7:
            // 这个 set 好象必须要放在这里的
            if( !query("go_where") )
                set("go_where", 2 + random( HJ_ROOM_AMOUNT -1 ) );
            add_action("do_answer","answer");
            break;
        case 2:
            add_action("do_lianli","lianli");
            break;
        case 3:
            add_action("do_huida","huida");
            break;
        case 5: case 6:
            add_action("do_found", "found" );
            add_action("do_foundall", "foundall" );
            break;
    }
}

int ask_help()
{
    switch(query("iii"))
    {
        case 0: case 4:
            command("hehe "+query("id"));
            command("say “我这里有一些东西可以买(gmai)，你也可以先看看价格表(glist)。”");
            break;
        case 1:
            if(!query("following_name"))
            {
                command("say “我迷路了啊……有个地方叫做「"+chinese_number(query("go_where"))
                    +"」的，你能带我去那里吗？(answer ok)”");
                remove_call_out("delete_me");
                call_out("delete_me",60);
            }
            else
                command("say “我迷路了，"+query("following_name")+"要带我去找「"
                    +chinese_number(query("go_where"))+"」呢。”");
            break;
        case 2:
            command("say “哦？这个啊……来，你打我一拳，让我看看你的力量有多高再说吧！”");
            command("say “不用怕，你小娃儿还伤不了我！我这就是准备让你炼力(lianli)呢！”");
            break;
        case 3:
            if( !query("asking_for_id") )
            {
                command("say “恩……江山代代新人来，这英雄二字，却不知有谁当得？”");
                command("say “你若知晓，可愿意回答我的提问(huida 好)？”");
            }
            else
                command("say “古往今来，多少英雄好汉？我又如何道尽你知？”");
            break;
        case 5:
            if( query("found_sword") != "yes" )
            {
                command("say “我听说有一柄"+query("finding_name")+"削铁如泥，端的是锋利异常，真想看一看。”");
                command("say “如果你能帮我找到(found 剑的id)，请告诉我好吗？”");
            }
            if( query("found_all_sword") != "yes" )
                command("say “我正在搜集一套宝剑，你能帮我找到的话(foundall)，请告诉我好吗？”");
            if( query("all_found") )
                command("haha");
            break;
        case 6:
        if( query("found_crystal") != "yes" )
        {
            command("say “我听说有一颗"+query("finding_name")+"神秘莫名，真想看一看。”");
            command("say “如果你能帮我找到(found 水晶的id)，请告诉我好吗？”");
        }
        if( query("found_all_crystal") != "yes" )
            command("say “我正在搜集一套魔法水晶，你能帮我找到的话(foundall)，请告诉我好吗？”");
        if( query("all_found") )
            command("haha");
            break;
    }
    return 1;
}

int do_found( string arg )
{
    object me = this_player(), ob = this_object(), f_obj;
    string f_name;
    int award_score;

    if( !me_ok(me) ) return 0;
    if(me->is_busy() || me->query_temp("hj_need_waitting") )
        return notify_fail("你还忙着呢，有空了才帮人吧。\n");

    if( !arg ) return notify_fail("你找到了什么？\n");
    f_obj = present( arg , me );
    if( !f_obj ) return notify_fail("你身上没有这样东西。\n");

    message_vision(CYN"$N"NOR+CYN"兴奋地拿出一"+f_obj->query("unit")+f_obj->name(1)+NOR+CYN"，对着$n"NOR+CYN"说道：“你是不是在找这个？”\n", me, ob );

    if( query("found_sword") == "yes" || query("found_crystal") == "yes" )
    {
        command("haha");
        command("say “在下已经见识过"+query("finding_name")+"了，有劳费心了。”");
        return 1;
    }

    f_name = query("finding_name");

    if( !f_obj->query("cj-sheng.zb-ke") || f_obj->query("cj-sheng.zb-ke") != ob
        || delcolor( f_obj->name(1) ) != f_name )
    {
        command("shake");
        command("say “这不是我要找的"+f_name+"。”");
        return 1;
    }

    // 正确了！
    f_obj->move( ob );
    command("ah");
    command("touch "+me->query("id"));
    command("say “对！这就是我要找的"+f_name+"！真是太感谢你了！”");
    message_vision( sprintf( CYN"$N"NOR+CYN"把%s"NOR+CYN"接了过去，审视良久，叹道：“这%s"NOR+CYN"我能得一见，已无憾矣！”\n", f_name, f_name ), ob );
    message_vision( CYN"$n"NOR+CYN"对$N"NOR+CYN"说道：“所谓宝物配英雄，这"+f_name+NOR+CYN"正是该由你所有！”\n$n"NOR+CYN"说完，把"+f_name+NOR+CYN"又交回了$N"NOR+CYN"手中。\n"NOR, me, ob);

    // 本任务主要是能够得到超级道具奖励
    f_obj->set("power", f_obj->query("power") * 2 );
    if( f_obj->query("power") > 50 )
        f_obj->set("power", 50 );
    f_obj->set("use_times", f_obj->query("use_times") * 2 );
    if( f_obj->query("use_times") > 20 )
        f_obj->set("use_times", 20);

    award_score = 30 + random(21);
    f_obj->move( me );
    message_vision(CYN"$N"NOR+CYN"只觉得$n"NOR+CYN"入手沉甸，已不似原先的感觉。\n"NOR, me, f_obj);
    write(HIR"游戏提示：你的得分增加了 "+award_score+" 点！\n"NOR);
    me->add_temp("hj_score", award_score );

    set( "found_sword", "yes" );
    set( "found_crystal", "yes" );

    if( query("found_all_sword") == "yes" || query("found_all_crystal") == "yes" )
    {
        set("all_found", 1);
        remove_call_out("delete_me");
        call_out("delete_me", 3 );
    }

    return 1;
}

int do_foundall()
{
    object me = this_player(), ob = this_object(), *temp_obj_list, temp_obj;
    string *found_list_id, msg, to_say;
    int i, award_score;

    if( !me_ok(me) ) return 0;
    if(me->is_busy() || me->query_temp("hj_need_waitting") )
        return notify_fail("你还忙着呢，有空了才帮人吧。\n");

    if( query("iii") == 5 )
    {
        msg = "剑";
        found_list_id = ({ "qt jian", "lq jian", "by jian", "bs jian",
            "yd jian", "hj jian", "nl jian", "xy jian", "dh jian", });
    }
    else
    {
        msg = "水晶";
        found_list_id = ({ "kf sj", "by sj", "ll sj", "yd sj",
                "gs sj", "fh sj","dh sj", });
    }

    message_vision(CYN"$N"NOR+CYN"冲着$n"NOR+CYN"兴奋地说道：“我找齐那一套"+msg+"了！”\n"NOR, me, ob );

    if( query("found_all_sword") == "yes" || query("found_all_crystal") == "yes" )
    {
        command("haha");
        command("say “在下已经找齐这一套"+msg+"，有劳费心了。”");
        return 1;
    }

    // 判断开始
    command( "oh2" );
    command( "say “快，让我看看！”" );
    to_say = CYN"$N"NOR+CYN"细细数道：“我看看……";

    temp_obj_list = ({ });
    for( i=0; i<sizeof(found_list_id); i++ )
    {
        temp_obj = present( found_list_id[i] , me );
        if( !temp_obj ) break;
        if( i == 0 )
            to_say += temp_obj->name(1) + NOR+CYN;
        else to_say += "、"+ temp_obj->name(1) + NOR+CYN;
        temp_obj_list += ({ temp_obj });
    }
    to_say += "……”\n"NOR;

    message_vision( to_say, ob );
    if( sizeof( temp_obj_list ) != sizeof( found_list_id ) )
    {
        command( "shake" );
        command( "say “你身上所带似乎并不齐全啊。”");
        return 1;
    }

    // 找齐了 :)
    // 把它们清理掉
    for( i = 0; i<sizeof( temp_obj_list ); i++ )
        destruct( temp_obj_list[i] );

    command("touch "+me->query("id") );
    command("say “对，对，就是这些"+msg+"，太好了，我终于找齐它们了！”");
    command("say “无以为报，请接受我的一点心意吧！”");
    message_vision( CYN"$n"NOR+CYN"接过了这一套"+msg+"，接着伸掌在$N"NOR+CYN"脸前一晃。\n"NOR, me, ob);

    if( query("iii") == 5 )
        award_score = 400 + random(101);
    else award_score = 300 + random(101);
    me->add_temp("hj_score", award_score );
    write(HIR"游戏提示：你的得分增加了 "+award_score+" 点！\n");

    set( "found_all_sword", "yes" );
    set( "found_all_crystal", "yes" );

    if( query("found_sword") == "yes" || query("found_crystal") == "yes" )
    {
        set("all_found", 1);
        remove_call_out("delete_me");
        call_out("delete_me", 3 );
    }

    return 1;
}


// 回答失败者，忙时 10 秒  未来得及回答者，若仍身处此地，忙时 20 秒
// 若已不见踪迹（就是溜了之类的），重惩，忙时 30 秒。
int do_huida(string arg)
{
    object qxd,me=this_player();
    mapping data1,data2,data3,data4;
    string qt_name1,qt_name2,qt_name3,qt_name4,*qt_type,temp_type;
    int i,qt_temp1,qt_temp2,qt_temp3,qt_temp4, score_is;

    if( !me_ok(me) ) return 0;

    qxd = present("qixing deng",me);
    if(!qxd) return 0;

    if(!qxd->query("hj_quest_info1") || !qxd->query("hj_quest_info2") ||
       !qxd->query("hj_quest_info3") || !qxd->query("hj_quest_info4") )
        return 0;

    if(me->is_busy() || me->query_temp("hj_need_waitting") )
        return notify_fail("你还忙着呢，空闲点了再接受提问吧。\n");

    if(query("asking_for_id") && me->query("id") != query("asking_for_id") )
        return notify_fail(query("name")+"已经在问着"+query("asking_for_name")+"了，还是不要打扰的好。\n");

    if(!arg) return notify_fail("你要回答什么？\n");

    if(!query("asking_for_id"))
    {
        if(arg!="好") return notify_fail("你若愿意接受提问，就回答“好”吧！\n");

    // 若玩家在本轮游戏里，已把5个预设的问题都答对过了，将不再发放问题。
        message_vision("$N大声说道：“好吧！你就尽管问我，看我知不知晓。”\n",me);
        if(sizeof( me->query_temp("hj_quest_answer") ) >=5 )
        {
            command("say “你所知武林之事甚多，看来非我之下。我又怎敢问你？”");
            command("smile");
            return 1;
        }

        remove_call_out("delete_me");
        set("asking_for_id",me->query("id"));
        set("asking_for_name",me->query("name"));
        set("asking","waiting");
        set("cannot_rdmove","yes");

        data1 = qxd->query("hj_quest_info1");
        data2 = qxd->query("hj_quest_info2");
        data3 = qxd->query("hj_quest_info3");
        data4 = qxd->query("hj_quest_info4");

        // 下面开始抽取问题类型
        
        qt_type = ({ "int","str","con","dex","balance" });
        // 悟性  膂力  根骨  身法  存款
        temp_type = qt_type[random(sizeof(qt_type))];
        // 防止玩家在本轮游戏内重复回答问题
        for(i=0;i<sizeof(qt_type);i++)
        {
            if(me->query_temp("hj_quest_answer/"+temp_type) == "ok")
                temp_type = qt_type[i];
            else break;
        }
        set("quest_type",temp_type);

        qt_name1 = data1["name"];
        qt_name2 = data2["name"];
        qt_name3 = data3["name"];
        qt_name4 = data4["name"];
        qt_temp1 = data1[temp_type];
        qt_temp2 = data2[temp_type];
        qt_temp3 = data3[temp_type];
        qt_temp4 = data4[temp_type];

        // 这里我不知道LPC是否有 max 的函数，只好自己写；幸好不太多数据
        if( qt_temp1>=qt_temp2 && qt_temp1>=qt_temp3 && qt_temp1>=qt_temp4 )
            set("the_answer",qt_name1);
        if( qt_temp2>=qt_temp1 && qt_temp2>=qt_temp3 && qt_temp2>=qt_temp4 )
            set("the_answer",qt_name2);
        if( qt_temp3>=qt_temp1 && qt_temp3>=qt_temp2 && qt_temp3>=qt_temp4 )
            set("the_answer",qt_name3);
        if( !query("the_answer") )
            set("the_answer",qt_name4);
        // 加入去掉颜色的句子，防止小BUG
        set("the_answer", delcolor( query("the_answer") ) );
        // 内部运作OK，告诉玩家去慢慢猜吧 :)
        command("nod");
        command("say “你是否听过这几个人？他们是 "+qt_name1+"、"+qt_name2+"、"+qt_name3+"和"+qt_name4+" 。”");
        switch(temp_type)
        {
            case "int":
            command("say “这其中一人，领悟之力奇高，因此过人一筹，终于了其心愿，\n          成就大事。如此之人，当称英雄！”");
            break;
            case "str":
            command("say “所谓英雄侠客，焉能有手无搏鸡之力之人？这其中一人，\n          力大无穷，堪堪劈石开山，也该配称英雄二字！”");
            break;
            case "con":
            command("say “人言道，吃得苦中苦，方为人上人。这其中一人，不但耐力\n          惊人，也是骨格精奇。如此之人，何愁不成大事，又有何不能称之英雄？”");
            break;
            case "dex":
            command("say “自古英雄皆好汉，但这里面却有一位，却非以武艺见长，乃是\n          天赋奇高，轻功过人，终闯出一片天地！如此之人，也该可称英雄！”");
            break;
            case "balance":
            command("say “有言云：一文难倒英雄汉。这其中一位，富敌四方，接朋济友，\n          虽无过人武艺，但又如何不能称之英雄？”");
            break;
        }
        command("say “你若知晓他的名字，就回答(huida)予我罢！”");
        message_vision("$N似有所悟，一时间呆住了，竟似忘了应声一般。\n",me);
        write(HIR"游戏提示：你只有60秒的时间！快快回答！\n"NOR);
        remove_call_out("delete_me");
        call_out("delete_me",61);
        return 1;
    }
    // 加入强制去除多余的空格的语句
    arg = replace_string( arg, " ", "" );
    arg = replace_string( arg, "　", "" ); // 连全角符号的“空白”也去掉。
    message_vision("$N想了想，说道：“这个人是"+arg+"！”\n",me);
    // 回答错误。
    if( arg != query("the_answer") )
    {
        set("asking","fail");
        remove_call_out("delete_me");
        command("sure "+me->query("id"));
        command("say “你说得不对。这个人哪，他的名字是"+query("the_answer")+"！”");
        message_vision("$N十分失望地说道：“这人如此有名，你竟然不知道！你仔细想想吧！”\n",this_object());
        message_vision("$N惭愧之色立现于脸，顿时陷入了沉思中。\n",me);
        me->start_busy(10);
        set("asking_for_id","no");
        call_out("delete_me",1);
        return 1;
    }
    // 回答正确！玩家得到奖励，并且设置值，本轮游戏内若再遇上老人，不会再提这个问题。
    remove_call_out("delete_me");
    message_vision("$N摸了摸胡子，说道：“不错！想不到你也能知晓他的名字！”\n",this_object());
    command("say “你所知如此之广，我有一物赠送予你。”");
    message_vision("老人说完，却不见拿出些什么来；只是突地把手往$N身上一拍！\n",me);
    message_vision("$N只觉得怪异莫名，却似乎又觉得有些什么变化……\n",me);
    me->set_temp("hj_quest_answer/"+query("quest_type"),"ok");
    if(me->query_temp("hj_score"))
    {
        score_is = 200 + random(101); // 最高可获 300 点奖励
        me->add_temp("hj_score", score_is );
        write(HIR"游戏提示：你的游戏得分增加了 "+score_is+" 点！\n"NOR);
    }
    set("asking","ok");
    call_out("delete_me",1);
    return 1;
}

// naihe 05-9-12 8:06 修改，lianli 成功时低忙时。
int do_lianli()
{
    object me=this_player();
    string id=me->query("id");
    int temp,power=me->query_temp("hj_game_mepower");

    if( !me_ok(me) ) return 0;

    if(!power) return 0;

    if(me->is_busy() || me->query_temp("hj_need_waiting"))
        return notify_fail("你还忙着呢，还是等空闲了，专心点来炼力吧！\n");

    if(me->query_temp("hj_hp") < power *2 )
        return notify_fail("你的气息太弱，无法使力打人，又如何炼力？\n");

    if(query("last_id") && query("last_id") == id )
    {
        command("say “哎呀，我已经教过你了，你怎么那么愚笨哪？”");
        return 1;
    }
    message_vision("$N大喝一声，使劲向着"+query("name")+"打出了一拳！\n",me);
    if( !random(3) )
    {
        me->start_busy(3+random(3));
        message_vision("只见$N用尽全力，却似打到了铜墙铁壁之上！$N顿时疼痛异常，感觉就似断了手臂一般！\n",me);
        me->add_temp("hj_hp", -power);
        message_vision(query("name")+"「呵呵」笑了笑，拍了拍$N的头说道：“娃儿的力气不对哪。”\n",me);
        this_object()->add("use_times",-1);
        if(query("use_times") <=0 )
        {
            remove_call_out("delete_me");
            call_out("delete_me",1);
        }
        return 1;

    }
    me->start_busy(1); // 炼力成功时只有1秒忙时。
    set("last_id",id);
    if(power<15)
    {
        message_vision("只见"+query("name")+"似是没知觉般全数受下了！\n",me);
        command("pat "+id);
        command("say “娃儿力气不行啊。来，我来教教你，要这般用力才对……”");
        temp=3+random(3);
    }
    else if(power<30)
    {
        message_vision("只听得「嘭」的一声，"+query("name")+"受下了这拳，但却只是微微一震！\n",me);
        command("nod");
        command("say “娃儿还有点力气。不过你用得不太对，我来教教你吧……”");
        temp=2+random(2);
    }
    else if(power<50)
    {
        message_vision("只听得一声重响，"+query("name")+"受下了这拳，登时往后退了一步！\n",me);
        command("consider");
        command("say “娃儿的力气不小哇！不过这还能打得更好，来来来，我来告诉你……”");
        temp=1+random(2);
    }
    else
    {
        message_vision("只听得"+query("name")+"闷哼一声受下这拳，登时往后退了好几步！\n",me);
        command("thumb "+id);
        command("say “娃儿的力气很不错哇！老头儿我告诉你这最后一点要领吧！……”");
        temp=1;
    }
    command("whisper "+id+" 这样这样，这样这样……明白了么？");
    message_vision("$N觉得茅塞顿开，顿时觉得力量似乎立竿见影般上涨了许多！\n",me);
    me->add_temp("hj_game_mepower",temp);
    this_object()->add("use_times",-1);
    if(query("use_times") <=0 )
    {
        remove_call_out("delete_me");
        call_out("delete_me",1);
    }
    return 1;
}

int do_answer(string arg)
{
    object me = this_player();
    int award_score;

    if( !me_ok(me) ) return 0;

    if(!arg || (arg!="ok" && arg!="byebye" && arg!="here?"))
        return notify_fail("回答什么？答应(ok)还是放弃(byebye)？或是找到了地方了(here?)？\n");

    if(arg == "ok")
    {
        if(query("following_name"))
        {
            if(me->query("id") == query("following_id"))
                write("你说了要带她去了的。\n");
            else command("say “"+query("following_name")+"说了要带我去了呀。”");
            return 1;
        }
        else
        {
            if(query("last_follow") == me->query("id"))
                return notify_fail("刚才你不是也说好吗！骗小孩子，不要脸～～\n");

            set("following_name",me->query("name"));
            set("following_id",me->query("id"));
            set("cannot_rdmove","yes");
            message_vision("$N对着"+query("name")+"大声说道：“我带你去吧！”\n",me);
            command("nod2 "+me->query("id"));
            command("say “我要去的是「"+chinese_number(query("go_where"))+"」啊。”");
            command("say “如果到了就告诉我(answer here?)，真是很感谢你啊！”");
            remove_call_out("delete_me");
            call_out("delete_me",180); // 这个任务很简单啦，3分钟有够多的了
            command("follow "+me->query("id"));
            return 1;
        }
    }

    if(arg == "byebye")
    {
        if(!query("following_id")) return notify_fail("还没答应她呢，就说拜拜！\n");
        if(me->query("id") != query("following_id") )
            return notify_fail("又不是你答应带她去的，你爱走便走么。\n");

        message_vision("$N挠了挠脑袋，对着"+query("name")+"说道：“我带不了你去了，就这样吧，我走了。”\n",me);
        delete("following_name");
        delete("following_id");
        command(":( "+me->query("id"));
        set("last_follow",me->query("id"));
        command("follow none");
        award_score = 5 + random(6);
        me->add_temp("hj_score", -award_score );
        if( me->query_temp( "hj_score" ) < 0 )
            me->set_temp( "hj_score", 0 );
        // 放弃答应的事情，将减少游戏得分。不过这还算是好的，起码明确表示放弃。将减少最多10点的得分；
        // 若是半途不见了、不管她之类的，那么，时限到了之后，将减少最多50点的得分。
        write("你心里感到一丝内疚！\n"HIR"游戏提示：你的得分减少了 "+award_score+" 点。\n"NOR);
        delete("cannot_rdmove");
        remove_call_out("random_move");
        call_out("random_move",1);
        remove_call_out("delete_me");
        add("use_times",-1);
        if(query("use_times") < 1)
            call_out("delete_me",1);
        else call_out("delete_me",30+random(31));
        return 1;
    }
    if(arg == "here?")
    {
        if(!query("following_id") || query("following_id") !=me->query("id") || !query("go_where") )
            return 0;
        if(environment( this_player() )->query("room_mark") != query("go_where") )
            return notify_fail(query("name")+"摇了摇头，说道：“好象不是这里啊。”\n");

        message_vision("$N向"+query("name")+"问道：“你是不是要来这里？”\n",me);
        command("jump");
        command("say “是啊！真的很谢谢你！”");
        set("go_where","ok");
        award_score = 50 + random(31);
        // 最高可获得 80 分的奖励！很不错啦。
        write("你帮助了别人，觉得愉快极了。\n"HIR"游戏提示：你的得分增加了 "+award_score+" 点！\n"NOR);
        me->add_temp("hj_score", award_score );
        remove_call_out("delete_me");        
        call_out("delete_me",1);
        return 1;
    }
    return 1;
}


// naihe 05-9-12 8:09 glist 时为什么要 cmd(say) ? 别人无缘无故就被 flood ，郁闷。
int do_glist()
{
    object me=this_player();
    int i,iii;
    string *lists,*for_debug,go_on="no";

    if( !me_ok(me) ) return 0;
    lists = keys(list_temp);
    for_debug= keys(all_values);
    write("----[ 共有以下共"+chinese_number(sizeof(lists))+"件 "+HIG+query("sell_this_time")+NOR+" 物品出售：]----\n\n");

    // 费尽心机，即学即用（之前什么叫映射我都不懂哎）
    // 写了个除了负担似乎比较大之外，还算自认为完美的防止bug判断流程
    // yeah 这下不怕了，obj_copy.h 里的映射变量乱改都没问题！哈哈哈
    // 8:29 02-10-30 
    for(i=0;i< sizeof(lists);i++)
    {
        for(iii=0;iii<sizeof(for_debug);iii++)
        {
            go_on="no";
            if(lists[i] != for_debug[iii]) continue;
            go_on="yes";
            break;
        }
        if(go_on == "yes")
            printf("%-10s( %-4s )     价格： %-30d\n",list_temp[lists[i]],lists[i],all_values[lists[i]]);
    }
    // 这里的 对齐 终于弄好啦，呵呵呵 太笨，以为是 (%-4)s 的，弄死都弄不好！ papaya
    write("\n----[ 用游戏积分购买货品，并且需要一个宝石才能买一件  指令：gmai 物品id ]----\n");
    return 1;
}

// naihe 05-9-12 8:15 gmai 时偶尔让NPC“无端端”地 say 出一句话来，除了购买时的玩家，别人会感到迷惑滴~~
int do_gmai(string arg)
{
    object money,gem,goods,me=this_player();  // goods  n.商品;货物
    string goods_name,have_gem="yes";
    int temp_set,temp_value;

    if( !me_ok(me) ) return 0;

    if( query("use_times") <= 0) return 0;

    if(!arg) return notify_fail("你要买什么东西？\n");


    if(sscanf(arg, "%s ok", goods_name) )
        have_gem="no";
    else goods_name = arg;

    if(have_gem == "yes")
    {
        gem = present("red baoshi",me);
        if(!gem) gem = present("blue baoshi",me);
        if(!gem) gem = present("green baoshi",me);
        if(!gem)
        {
            return notify_fail( "你没有宝石，如果你确实要买，价钱可得加倍。 <gmai 物品id ok>\n");
            return 1;
        }
    }

    if(!list_temp[goods_name] || !all_dir[goods_name] ||
       !all_set[goods_name] || !all_values[goods_name] )
        return notify_fail("没有这个东西卖。\n");

    temp_value = all_values[goods_name];
    if(have_gem == "no") temp_value += temp_value;
    if(!me->query_temp("hj_score") || me->query_temp("hj_score") <= temp_value)
        return notify_fail("你没有足够的游戏得分，不能够购买它。\n");
    goods=new(__DIR__+all_dir[goods_name]);
    if( all_set[goods_name] == 111) temp_set = 0;
    else temp_set = all_set[goods_name];
    goods->setme( temp_set );
    goods->move(me);
    me->add_temp("hj_score", -temp_value);
    if(have_gem == "yes")
    {
        message_vision(sprintf("$N掏出一%s%s，向%s买下了一%s%s。\n",
            gem->query("unit"),gem->query("name"),query("name"),
            goods->query("unit"),goods->query("name")),
            me
        );
        destruct(gem);
    }
    else
    {
        message_vision(sprintf("$N向%s买下了一%s%s。\n",
            query("name"),goods->query("unit"),goods->query("name")),
            me
        );
    }
    this_object()->add("use_times",-1);
    if(query("use_times") <=0 )
    {
        remove_call_out("delete_me");
        call_out("delete_me",1);
    }
    return 1;
}
