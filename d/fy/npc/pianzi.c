
#include <login.h>
#include <ansi.h>

inherit NPC;
object player;
// Whether playing with a player
int in_game, pturn, waited;
#define NP 6
#define MAXN 15
int* p=({0,0,0,0,0,0});

string pile="●●●●●●●●●●●●●●●●●●";
string cnum="①②③④⑤⑥⑦⑧⑨⑩";

void show(object who);
void ctake();

int CheckWin(object who)
{
    int i, j, k;
    object ob;
    
    j = player->query_temp("marks/win_pianzi");
    k = player->query_temp("marks/lose_pianzi");
    for(i=0;i<NP;i++)
        if(p[i]!=0) return 0;
    
    message_vision(HIR"$N赢了。\n"NOR,who);
    if(who==this_object()) {
//      player->set_temp("marks/lose_pianzi", k + 1);
        command("say 再来，再来，你刚才其实差一点就赢了。");
//              if (player->query_temp("marks/lose_pianzi") >= 3) {
//                      player->delete_temp("marks/lose_pianzi");
//                      remove_call_out("purple_sword");
//                      call_out("purple_sword", 2);
//              }
        player->delete_temp("marks/win_pianzi");
    } else {
        ob=new("/obj/money/gold");
        ob->set_amount(2);
        ob->move(this_object());
//        player->delete_temp("marks/lose_pianzi");
        player->set_temp("marks/win_pianzi", j + 1);
        command("say 佩服，佩服，这是你的二两金锭。");
        command("give gold to "+player->query("id"));
        if (player->query_temp("marks/win_pianzi") == 2) {
//              remove_call_out("purple_sword");
                call_out("purple_sword", 1);
        }       
    }
    in_game=0;
    return 1;
} 

void take(object who, int which, int howmany)
{
    p[which]-=howmany;
    message_vision("$N从第"+chinese_number(which+1)+
                   "堆里拿走了"+chinese_number(howmany)+"粒小石子。\n",who);
    show(0);
    CheckWin(who);
}


void show(object who)
{
    int i;
    for(i=0;i<NP;i++)
        if(p[i]!=0)
            if(who==0)
                message_vision(CYN+cnum[i..i]+NOR"："GRN+
                               pile[0..p[i]-1]+NOR"\n",
                               this_object());
            else tell_object(who,CYN+cnum[i..i]+NOR"："GRN+
                               pile[0..p[i]-1]+NOR"\n");
}

int do_show()
{
    if(in_game==1 && player==this_player())
    {
        show(this_player());
        return 1;
    }
    return 0;
}

int do_take(string arg)
{
    int i,h;
    if(in_game==1 && player==this_player())
    {
        if(!arg || sscanf(arg,"%d %d",i,h)!=2)
            return notify_fail("指令格式：take <第几堆> <拿几个>\n");
        
        if(i>NP || i<=0) return notify_fail("你只能选择第一到第"+
                                            chinese_number(NP)+"堆。\n");
        if(h>p[i-1]) return notify_fail("第"+chinese_number(i)+
                                                "堆里没这么多石子。\n");
        if(h<=0) return notify_fail("你只能拿一个以上的石子。\n");
        if(pturn!=1)
            return notify_fail("还没轮到你呢。\n");
        
        take(this_player(), i-1, h);
        remove_call_out("hurry");
        remove_call_out("ctake");
        if(in_game)
        {
            pturn=0;
            call_out("ctake",1);
        }
        return 1;
    }
    return 0;
}
    
int do_resign()
{
        int k;
        
        k = player->query_temp("marks/lose_pianzi");
    if(in_game==1 && player==this_player())
    {
        message_vision("$N认输了。\n",player);
        command("say 怎么不玩了，你还有希望赢的．．．");
//              player->set_temp("marks/lose_pianzi", k + 1);
                player->delete_temp("marks/win_pianzi");
//        if (player->query_temp("marks/lose_pianzi") >= 3) {
//              player->delete_temp("marks/lose_pianzi");
//         remove_call_out("purple_sword");
//              call_out("purple_sword", 2);
//        }
        in_game=0;
        return 1;
    }
    return 0;
} 

void ctake()
{
    int sum, i, j;
    int best=100, besti=-1;
    object ob;
    
    j = player->query_temp("marks/win_pianzi");
    for(i=0,sum=0;i<NP;i++)
        sum^=p[i];
    if(sum==0)
    {
        for(i=0;i<NP;i++)
            sum|=p[i];
        if(sum & 8) sum=15;
        else if(sum & 4) sum=7;
        else if(sum & 2) sum=3;
        else
        {
            command("say 我认输了。\n");
            ob=new("/obj/money/silver");
            ob->set_amount(2);
            ob->move(this_object());
            player->delete_temp("marks/lose_pianzi");
            player->set_temp("marks/win_pianzi", j + 1);
            command("say 佩服，佩服，这是你的二两银子。");
            command("give silver to "+player->get_id());
            in_game=0;
            return;
        }
    }
    for(i=0;i<NP;i++)
        if(p[i] > (p[i]^sum) && (best > p[i]-(p[i]^sum)))
        {
            best=p[i]-(p[i]^sum);
            besti=i;
        }
    if(besti!=-1)
    {
        take(this_object(),besti, best);
        if(in_game)
        {
            message_vision(RED"该$N了。\n"NOR, player);
            pturn=1;waited=0;
            call_out("hurry",10);
        }
        return;
    }
    command("say shit!不玩了\n");
    message_vision("$N把石子收了起来。\n"NOR, this_object());
    in_game=0;
}

int do_start()
{
    int i,sum=0;
    object silver;
    int *mp;
    
    if(in_game==1) 
        return notify_fail(HIC"江湖骗子"NOR"在和"+player->name()+"玩着呢。\n");
    //Check for money...
    player=this_player();
    silver=present("silver_money", player);
    if(!silver) return notify_fail("你身上没有银子呀。\n");
    silver->add_amount(-1);
                   
    in_game=1;

    mp=allocate(MAXN*4);
    for(i=0;i<MAXN;i++)
        mp[i]=0;
    for(i=0;i<NP-1;i++)
    {
        p[i]=random(MAXN)+1;
        if(mp[p[i]]==0)
        {
            mp[p[i]]++;
            sum^=p[i];
        }
        else i--;
    }
    if(random(3))  p[NP-1]=sum;
    else p[NP-1]=random(MAXN)+1;
    
    command("say 规则很简单，大家轮流拿石子，谁先拿到最后一个谁就赢了。");
    command("say 你可以认输（resign），或查看状态（show）。");

    show(0);
    message_vision(RED"$N先拿（take）吧。\n"NOR, player);
    pturn=1; waited=0;
    call_out("hurry",10);
    return 1;
}

void hurry()
{
    remove_call_out("hurry");
    if(in_game==0) return;

    if(random(10)==0 && present("old beggar",environment()))
    {
        command("say 这群乞丐真讨厌！");
        call_out("hurry",10);
        return;
    }    

    if( !player || environment(player) != environment() )
    {
        command("say 咦？人怎么走了？");
        message_vision("$N把石子收了起来。\n"NOR, this_object());
        in_game=0;
    }
    else
    {
        waited+=1;
        if(waited > 5)
        {
            command("say 反应太慢，不跟你玩了。");
            message_vision("$N把石子收了起来。\n"NOR, this_object());
            in_game=0;
        }
        else
        {
            command("say 快点决定吧，别犹豫了。");
            call_out("hurry",10);
        }
    }
    return;
}

void create()
{
    set_name(HIC"江湖骗子"NOR, ({ "jianghu pianzi","pianzi" }) );
    set("title",HIY "童叟无欺"NOR);
        set("long", "一个靠耍小把戏骗人为生的江湖骗子。\n");
    set("gender", "男性");
    set("age", 70);
    set("no_fight",1);
    set("NO_KILL",1);
    set("inquiry",([
        "幽冥紫晶" :"没听说过。\n",
        "心服口服" :"吹牛皮谁不会，先拿点真功夫出来吧。\n",
        "聪慧绝顶":	"action江湖骗子自豪地指了指自己。\n",
      ]) );
              
    set("combat_exp", 9000);
    setup();
    carry_object("/obj/armor/cloth")->wear();
    in_game = 0;
}

void init()
{
    object ob;
    ::init();
    //if( !query_heart_beat(this_object()) ) set_heart_beat(1);
    add_action("do_take", "take");
    add_action("do_show","show");
    add_action("do_resign","resign");
    add_action("do_start","play");
	add_action("do_answer", "answer");
    if( interactive(ob = this_player()) && !is_fighting() )
    {
        remove_call_out("greeting");
        call_out("greeting", 1, ob);
    }
}

void greeting(object ob)
{
    if( !ob || environment(ob) != environment() ) return;

    message_vision( "$N笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                    +"，来和我玩个小游戏吧（play），赌一两银子，怎么样？\n",
                    this_object());

}

int purple_sword() {
	message_vision("$N盯着$n的脸，注视了良久。\n", this_object(), player); 
	message_vision("$N对着$n说：“我闯荡江湖，还从来没有见过" + RANK_D->query_respect(player) + "这样大智大慧的人物。\n", 
			this_object(), player);
	message_vision("宝剑应随真主，我有一把幽冥紫灵剑，你可愿意买下？” （ａｎｓｗｅｒ　ｙｅｓ／ｎｏ）\n", this_object());
	player->set_temp("pianzi_yes_no", 1);
	return 1;
}

int do_answer(string arg){
	object player, sword;
	
	player = this_player();
	if (player->query_temp("pianzi_yes_no")) {
		if (arg == "yes") {
			player->set("marks/买幽冥紫灵剑", 1); 
			message_vision("$N说道：这位" + RANK_D->query_respect(player) + "果然有见地，给我一百两金子就行了。\n", 
					this_object(), player);
			player->delete_temp("pianzi_yes_no");
			return 1;
		} else if (arg == "no") {
			message_vision("$N叹了口气说道：“可惜，可惜如此地府神兵，竟然无人赏识！”\n", this_object());
			player->delete_temp("pianzi_yes_no");
			return 1;
		} else {
			tell_object(player,"answer yes/no");
			return 1;
		}
	} 
	return 0;
}


// You got the sword if you solve it and give out 100g
// But you might not be able to continue to the next step, 
// So, i will let you pawn it and let you keep a mark.
int accept_object(object who, object ob) {
	object player, sword;
	
	player = this_player();
	if (!player->query("marks/买幽冥紫灵剑")) {
		return 0;
	}
	if (ob->query("money_id") != "gold") {
		return 0;
	}
	if (ob->query("money_id") == "gold" ) {
		if (ob->query_amount() < 100) {
			message_vision("$N不满意地说：“你觉得如此灵剑就值这个价钱？”\n", this_object());
		} else {
			sword = new(__DIR__"obj/purple_sword");
			if (sword) {
				message_vision("$N小心地从怀中取出一把宝剑交给$n嘀咕道：“你可莫辜负了灵剑。” \n", 
					this_object(), player); 
//				sword->set("sword_owner", player->name());	//No point, as long as you have the mark you're good				
				if (sword->move(player)) {
					player->delete("marks/买幽冥紫灵剑");
					REWARD_D->riddle_set(player,"幽冥紫晶",1);
				} else { 
					destruct(sword);
					ccommand("say OOPS，你带的东西太多了！");
				}
			}
			return 1;
		}
	}		
}
