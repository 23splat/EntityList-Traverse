
std::vector<DWORD> getPlayerHP(DWORD OPHealth, DWORD EntityList, DWORD PlayersInGame)
{
    std::vector<DWORD> PlayerHealth;

    for (int j = 0; j < PlayersInGame; j++)
    {
        DWORD currentPlayer = rpm<DWORD>(EntityList + (j * 0x4), Holder::hProcessAC); // each player is 4 bytes apart under entitylist
        DWORD currentPlayerHealthAddr = currentPlayer + 0xEC;
        DWORD currentPlayerHP = rpm<DWORD>(currentPlayerHealthAddr, Holder::hProcessAC);

        PlayerHealth.push_back(currentPlayerHP);
    }
    return PlayerHealth;
}
