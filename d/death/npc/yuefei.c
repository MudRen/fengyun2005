// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("常胜将军", ({ "master yue", "master" }) );
        set("nickname", HIY"金盔"HIW"银甲"NOR);
        set("gender", "男性" );
	set("class","official");
	        
        set("cor", 50);
        set("attitude","heroism");
                
	set("rank_nogen",1); 
        create_family("朝廷命官", 5, "鄂武穆王");  
	set("family/master_id", "master yue");	// for perform 7-hit spear.
	
        set("long","你看着看着，觉得这位将军就象是当年统兵十万，直捣黄龙，壮志未酬的岳飞！\n");
        
        set("combat_exp", 8000000);
                    
        set_skill("unarmed",190);
        set_skill("parry", 190);
        set_skill("dodge", 200);
        set_skill("advanced-unarmed",100);
        set_skill("spear", 300);
        
        set_skill("foreknowledge",100);
        set_skill("force", 160);
        set_skill("chanting",100);	
        set_skill("move", 160);
        set_skill("leadership",250);
		set_skill("strategy",250);
		set_skill("perception", 100);
        set_skill("foreknowledge",100);  
        
        set_skill("changquan",220);
        set_skill("yue-spear",180);
        set_skill("manjianghong",150);
        set_skill("puti-steps",200);
        set_skill("literate", 100);
        
        map_skill("unarmed","changquan");
        map_skill("dodge","puti-steps");
	map_skill("force", "manjianghong");
	map_skill("spear","yue-spear");
	map_skill("parry","yue-spear");
	map_skill("move", "puti-steps");

	set_temp("apply/attack",200);
	set_temp("apply/dodge", 200);
	set_temp("apply/parry", 200);
	set_temp("apply/damage", 100);
        set_temp("apply/armor", 100);
        	
	set("marks/官府/岳飞",	1);
	
	set("chat_chance_combat",50);
        set("chat_msg_combat", ({
        	(: perform_action, "spear.zonghengtianxia" :)
        }) );
	
	setup();
        carry_object(__DIR__"obj/goldarmor")->wear();
        carry_object(__DIR__"obj/silverarmor")->wear();
        carry_object("/obj/weapon/spear")->wield();
}


int is_ghost() { return 1; }

void attempt_apprentice(object ob)
{
        if (REWARD_D->check_m_success(ob,"纵横天下") && ob->query("class") == "official")	{
 //       if( ob->query("marks/官府/岳飞")&&ob->query("class")=="official" ) {
        	command("smile");
        	command("say 你须谨记“精忠报国”这四个字。");
        	command("recruit " + ob->query("id") );
        }
 
}


void do_recruit(object ob)
{
         if( ::recruit_apprentice(ob) ) {
        	ob->set("class", "official");
    		ob->set("vendetta_mark", "authority");
    	}
}



void re_rank(object student)
{
//      int exp;
		ccommand("emote 微笑道：此身已非尘世中人，恕岳某无能为力。");
		ccommand("emote 又道：若要求官进爵，汝可去寻当今圣上之明珠，传闻她私常偷溜出宫游玩。");

        return ;
}

/*
　 岳  飞
 
　 
    岳飞(1103～1142)，南宋名将。字鹏举。相州汤阴(今属河南)人。
    幼年家贫，由其母亲自授学。宋徽宗宣和四年(1122)应募敢战士，参加守边。其后在抗金战斗中屡建功勋，
    历任武安军承宣使，荆南、鄂岳州制置使，检校少保。后进封公，拜太尉，授少保，任枢密副使。
    宋高宗绍兴十一年岁暮（1142年1月27日）,被主和派权臣秦桧诬陷杀害。孝宗时追谥武穆。后改谥忠武。宁宗时追封鄂王。
    岳飞精韬略,善运筹,博采众谋，强调运用之妙,存乎一心。严于治军,重视选将,信赏明罚,爱护士卒。
    其军以“冻死不拆屋,饿死不掳掠”(《宋史·岳飞传》)著称。常能以少胜众。金军叹称:“撼山易，撼岳家军难！”
　　他的诗如《送紫岩张先生北伐》中的警句“马蹀阏氏血，旗枭可汗头”，慷慨激切。
    他的词《满江红》、《小重山》二阕，或以忠愤之气动人心魄，或以幽怨之情感人肺腑，
    一直为后世所传诵。只是《满江红》不见于岳飞之孙岳珂的《金陀粹编》中，
    至明代宗景泰六年(1455)袁纯所编《精忠录》始加收录，故近人余嘉锡《四库提要辨证》、
    今人夏承焘《岳飞〈满江红〉词考辨》等文，皆对此词作者、作年提出疑问。有著作《岳忠武王文集》10卷。
　
 
 

满江红

    怒发冲冠，凭栏处，潇潇雨歇。抬望眼，仰天长啸，壮怀激烈。三十功名尘与土，八千里路云和月。莫等闲，白了少年头，空悲切。

    靖康耻，犹未雪；臣子恨，何时灭！驾长车踏破贺兰山缺。壮志饥餐胡虏肉，笑谈渴饮匈奴血。待从头，收拾旧山河，朝天阙。
　

满江红·登黄鹤楼有感

    遥望中原，荒烟外、许多城郭。想当年、花遮柳护，凤楼龙阁。万岁山前珠翠绕，蓬壶殿里笙歌作。到而今、铁蹄满郊畿，风尘恶。

    兵安在，膏锋锷。民安在，填沟壑。叹江山如故，千村寥落。何日请缨提锐旅，一鞭直渡清河洛。却归来、再续汉阳游，骑黄鹤。
　

送紫岩张先生北伐

号令风霆迅，天声动北陬。
长驱渡河洛，直捣向燕幽。
马蹀阏氏血，旗枭可汗头。
归来报明主，恢复旧神州。
　

题鄱阳龙居寺

巍石山前寺，林泉胜复幽。
紫金诸佛相，白雪老僧头。
潭水寒生月，松风夜带秋。
我来瞩龙语，为雨济民忧。
　

池州翠微亭

经年尘土满征衣，特特寻芳上翠微。
好水好山看不足，马蹄催趁月明归。
　

题雩都华严寺

手持竹杖访黄龙，旧穴空遗虎子踪。
云锁断岩无觅处，半山松竹撼秋风。
　

驻兵新淦题伏魔寺壁

雄气堂堂贯斗牛，誓将直节报君仇。
斩除顽恶还车驾，不问登坛万户侯。
　

过张溪赠张完

无心买酒谒青春，对镜空嗟白发新。
花下少年应笑我，垂垂赢马访高人。


小重山

昨夜寒蛩不住鸣。惊回千里梦，已三更。起来独自绕阶行。人悄悄，帘外月胧明。

白首为功名。旧山松竹老，阻归程。欲将心事付瑶琴。知音少，弦断有谁听。
　

题翠岩寺

秋风江上驻王师，暂向云中蹑翠微。
忠义必期清塞水，功名直欲镇边圻。
山林啸聚何劳取，沙漠群凶定破机。
行复三关迎二圣，金酋席卷尽擒归。
　

题骤马岗

立马林岗豁战眸，阵云开处一溪流。
机舂水沾犹传晋，黍离宫庭孰悯周?
南服只今歼小丑，北辕何日返神州!
誓将七尺酬明圣，怒指天涯泪不收。
　

驻军盆珠

云屯壁垒夜鸣铮，帐拥珠岗翠色萦。
但使狐鼪乞一活，何须血刃下孤城。
日连旗影蚕洲暗，光拂剑花遂水横。
虔吉未平归未得，何时廓字罢天兵? 
　

宝刀歌·赠吴将军南行

我有一宝刀，
深藏未出韬。
今朝持赠南征使，
紫蜺万丈干青霄。
指海海腾沸，
指山山动摇。
蛟鳄潜形百怪伏，
虎豹战服万鬼号。
时作龙吟似怀恨，
咻得尽剿诸天骄。
蠢尔蛮蜑弄竿梃，
倏聚忽散如群猱。
使君拜命仗此往，
红炉炽炭燎氄毛。
奏凯归来报天子，
云台麟阁高瞧嶢。
噫嘻!
平蛮易，自治劳，
卒犯市肆，马躏禾苗。
将躭骄侈，士狃贪饕。
虚张囚馘，妄邀金貂。
使君一一试此刀，
能令四海烽尘消，
万姓鼓舞歌唐尧。
 

 
*/