#ifndef MODULE_BREAKINGNEWS_H
#define MODULE_BREAKINGNEWS_H

#include "ScriptMgr.h"
#include "WardenWin.h"
#include "Player.h"
#include "Config.h"

#include <fstream>
#include <iostream>

bool bn_Enabled;

std::string bn_Title;
std::string bn_Body;
std::string bn_Formatted;

std::string _prePayload = "wlbuf = '';";
std::string _postPayload = "loadstring(wlbuf)();wlbuf = nil;";
uint16 _prePayloadId = 5500;
uint16 _postPayloadId = 5501;
uint16 _tmpPayloadId = 5502;

std::vector<std::string> GetChunks(std::string s, uint8_t chunkSize);
void SendChunkedPayload(Warden* warden, std::string payload, uint32 chunkSize);

class BreakingNewsServerScript : ServerScript
{
public:
    BreakingNewsServerScript() : ServerScript("BreakingNewsServerScript") { }

private:
    bool CanPacketSend(WorldSession* session, WorldPacket& packet) override;
};

class BreakingNewsWorldScript : public WorldScript
{
public:
    BreakingNewsWorldScript() : WorldScript("BreakingNewsWorldScript") { }

private:
    bool TryReadFile(std::string& path, std::string& bn_Result);
    void OnAfterConfigLoad(bool reload) override;
};

#endif //MODULE_BREAKINGNEWS_H
